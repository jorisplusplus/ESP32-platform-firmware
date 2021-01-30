#include <sdkconfig.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <esp_err.h>
#include <esp_log.h>
#include <driver/uart.h>
#include <driver/gpio.h>
#include <esp_vfs.h>
#include <dirent.h>
#include <esp_intr_alloc.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/timers.h"

#include "include/driver_fsoverbus.h"
#include "include/filefunctions.h"
#include "include/packetutils.h"
#include "include/specialfunctions.h"
#include "include/fsob_backend.h"

//TEMP
#include <driver/spi_master.h>


#ifdef CONFIG_DRIVER_FSOVERBUS_ENABLE

void vTimeoutFunction( TimerHandle_t xTimer );

#define TAG "FSoverBus"

TimerHandle_t timeout;
RingbufHandle_t buf_handle[2];

uint8_t command_in[1024];

#define min(a,b) (((a) < (b)) ? (a) : (b))

//Function lookup tables

int (*specialfunction[])(uint8_t *data, uint16_t command, uint32_t message_id, uint32_t size, uint32_t received, uint32_t length) = {execfile, heartbeat, pythonstdin};
int specialfunction_size = 3;
                         //                                                                                  4096    4097      4098       4099     4100      4101    4102
int (*filefunction[])(uint8_t *data, uint16_t command, uint32_t message_id, uint32_t size, uint32_t received, uint32_t length) = {getdir, readfile, writefile, delfile, duplfile, mvfile, makedir};
int filefunction_size = 7;

void handleFSCommand(uint8_t *data, uint16_t command, uint32_t message_id, uint32_t size, uint32_t received, uint32_t length) {
    static uint32_t write_pos;
    if(received == length) { //First data of the packet
        write_pos = 0;
    }

    if(length > 0) {
        memcpy(&command_in[write_pos], data, length);
        write_pos += length;
    }

    int return_val = 0;
    if(command < 4096) {
        if(command < specialfunction_size) {
            return_val = specialfunction[command](command_in, command, message_id, size, received, length);
        }
    } else if(command < 8192) {
        if((command-4096) < filefunction_size) {
            return_val = filefunction[command-4096](command_in, command, message_id, size, received, length);
        }
    }
    if(return_val) {    //Function has indicated that next payload should write at start of buffer.
        write_pos = 0;
    }
}

void vTimeoutFunction( TimerHandle_t xTimer ) {
    ESP_LOGI(TAG, "Saw no message for 1s assuming task crashed. Resetting...");
    fsob_reset();
}

void fsob_stop_timeout() {
     xTimerStop(timeout, 1);
}

void fsob_start_timeout() {
    xTimerStart(timeout, 1);
}

//Temp
static const spi_bus_config_t buscfg = {
		.mosi_io_num     = 23,
		.miso_io_num     = 35,
		.sclk_io_num     = 18,
		.max_transfer_sz = 19
	};

spi_device_handle_t handle;

spi_device_interface_config_t devcfg={
        .command_bits=0,
        .address_bits=0,
        .dummy_bits=0,
        .clock_speed_hz=500000,
        .duty_cycle_pos=128,
        .mode=0,
        .spics_io_num=19,
        .queue_size=3
    };

void process_miso(uint8_t *data) {
    static uint32_t counter = 0;
    if(data[1] == 0xF0) {
        uint8_t valid_bytes = data[0];
        counter += valid_bytes;
        ESP_LOGD(TAG, "Total received: %d", counter);        
        fsob_receive_bytes(&data[2], valid_bytes);
                
    }
}

SemaphoreHandle_t SemaphoreHandle1 = NULL;

void stm32_task() {
    for( ;; ) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY );
        xSemaphoreTake(SemaphoreHandle1, portMAX_DELAY);
        spi_device_acquire_bus(handle, portMAX_DELAY);
        ESP_LOGI(TAG, "Acquired spi");
        while(!gpio_get_level(GPIO_NUM_0)) {
            ets_delay_us(1000); //Delay here to not overload the stm32
            uint8_t mosi[18] = {0};
            uint8_t miso[18] = {0};
            spi_transaction_t t = {
            .length = 18*8,
            .rxlength = 18*8,
            .tx_buffer = mosi,
            .rx_buffer = miso
            };
            spi_device_transmit(handle, &t);
            process_miso(&miso[9]);
        }
        ESP_LOGI(TAG, "Released spi");
        spi_device_release_bus(handle);
        xSemaphoreGive(SemaphoreHandle1);
    }
}

static TaskHandle_t stm32_task_handle = NULL;

void gpio0_intr() {
     xTaskNotifyGive(stm32_task_handle);
}



void spi_init() {
    SemaphoreHandle1 = xSemaphoreCreateBinary();
    xSemaphoreGive(SemaphoreHandle1);
    esp_err_t res = spi_bus_initialize(VSPI_HOST, &buscfg, 1);
    gpio_set_direction(19, GPIO_MODE_OUTPUT);
    spi_bus_add_device(VSPI_HOST, &devcfg, &handle);

    gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT);
    gpio_isr_handler_add(GPIO_NUM_0, gpio0_intr, NULL);
    gpio_set_intr_type(GPIO_NUM_0, GPIO_INTR_NEGEDGE);
    gpio_intr_enable(GPIO_NUM_0);

    xTaskCreatePinnedToCore(stm32_task, "fsoverbus_spi", 16000, NULL, 100, &stm32_task_handle, 0);

}

void fsob_write_bytes(const char *src, size_t src_size) {
    xSemaphoreTake(SemaphoreHandle1, portMAX_DELAY);
    spi_device_acquire_bus(handle, portMAX_DELAY);
    ESP_LOGI(TAG, "Acquired spi");
    while (src_size > 0) {
        ets_delay_us(1000); //Delay here to not overload the stm32
        uint8_t mosi[18] = {0};
        uint8_t miso[18] = {0};
        mosi[1] = 0xF0;
        mosi[0] = min(src_size, 12);
        memcpy(&mosi[2], src, mosi[0]);
        src += mosi[0]; //Increment src pointer with bytes copied
        src_size = src_size - mosi[0]; //Decrement remaining bytes to transmit
        spi_transaction_t t = {
        .length = 18*8,
        .rxlength = 18*8,
        .tx_buffer = mosi,
        .rx_buffer = miso
        };
        spi_device_transmit(handle, &t);        
        process_miso(&miso[9]);        
    }
    ESP_LOGI(TAG, "Released spi");
    spi_device_release_bus(handle);
    xSemaphoreGive(SemaphoreHandle1);
}



//Temp end
esp_err_t driver_fsoverbus_init(void) { 

    buf_handle[0] = xRingbufferCreate(2048, RINGBUF_TYPE_BYTEBUF);
    buf_handle[1] = xRingbufferCreate(2048, RINGBUF_TYPE_BYTEBUF);

    fsob_init();
    spi_init();

    ESP_LOGI(TAG, "fs over bus registered.");
    
    timeout = xTimerCreate("FSoverBUS_timeout", 100, false, 0, vTimeoutFunction);
    return ESP_OK;
} 

#if CONFIG_DRIVER_FSOVERBUS_NOBACKEND_HELPER

#else

#endif

#else
esp_err_t driver_fsoverbus_init(void) { return ESP_OK; } //Dummy function.
#endif