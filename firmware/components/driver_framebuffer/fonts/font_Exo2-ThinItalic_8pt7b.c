#include "../include/driver_framebuffer.h"
const uint8_t Exo2_ThinItalic_8pt7bBitmaps[] = {
  0x00, 0xFA, 0xE0, 0x24, 0xA7, 0xD2, 0xF9, 0x45, 0x00, 0x13, 0xD8, 0xC3,
  0x14, 0xB6, 0x40, 0xE6, 0xAB, 0xFD, 0x35, 0x59, 0xC0, 0x78, 0x81, 0x13,
  0xF8, 0x51, 0x3C, 0x00, 0xC0, 0x6A, 0xAA, 0x44, 0x92, 0x56, 0x5F, 0x00,
  0x4B, 0xA0, 0xC0, 0xE0, 0x80, 0x08, 0x84, 0x44, 0x22, 0x00, 0xF9, 0x99,
  0x99, 0xE0, 0xD5, 0x68, 0x78, 0x44, 0x22, 0x23, 0xC0, 0x71, 0x16, 0x11,
  0xF0, 0x21, 0x53, 0x17, 0x88, 0x40, 0x74, 0x61, 0x11, 0xE0, 0xF8, 0xE9,
  0x99, 0xE0, 0xF2, 0x22, 0x44, 0x80, 0xF9, 0x96, 0x99, 0xE0, 0xF9, 0x99,
  0xF2, 0xE0, 0x90, 0x98, 0x71, 0x80, 0xF0, 0xE0, 0x61, 0xE0, 0xE4, 0xA4,
  0x20, 0xF0, 0x5B, 0x3A, 0xD7, 0xE0, 0x11, 0x94, 0x97, 0x46, 0x20, 0xF9,
  0x9E, 0x99, 0xF0, 0x78, 0x88, 0x88, 0xE0, 0xF9, 0x99, 0x99, 0xF0, 0xF8,
  0x8E, 0x88, 0xE0, 0xF8, 0x8E, 0x88, 0x80, 0x78, 0x89, 0x99, 0xF0, 0x99,
  0x9F, 0x99, 0x90, 0xFE, 0x24, 0xA4, 0xB0, 0x9A, 0xAC, 0xCA, 0xA0, 0x92,
  0x49, 0x38, 0x42, 0x8D, 0x9B, 0x3A, 0xB2, 0x64, 0x80, 0x8E, 0x73, 0x5A,
  0xDA, 0x40, 0x79, 0x99, 0x99, 0xF0, 0xF9, 0x9E, 0x88, 0x80, 0x79, 0x99,
  0x99, 0xB4, 0x20, 0xF9, 0x9E, 0x99, 0x90, 0x7A, 0x10, 0x60, 0x87, 0xC0,
  0xF4, 0x44, 0x44, 0x40, 0x8C, 0x63, 0x19, 0x4B, 0xC0, 0x8C, 0xA5, 0x4A,
  0x51, 0x00, 0x91, 0xB2, 0xAA, 0xAA, 0xCC, 0xCC, 0x88, 0x4A, 0x4C, 0x45,
  0x2A, 0x20, 0x99, 0xA4, 0x44, 0x40, 0x78, 0x84, 0x44, 0x23, 0xC0, 0x29,
  0x25, 0x24, 0x98, 0x92, 0x24, 0x88, 0x55, 0x55, 0x60, 0x74, 0xF0, 0x80,
  0xF6, 0xDE, 0x44, 0x79, 0x99, 0xF0, 0x78, 0x88, 0xF0, 0x11, 0xF9, 0x9A,
  0xE0, 0x79, 0xE8, 0xF0, 0x39, 0x1C, 0x42, 0x21, 0x08, 0xC0, 0x7C, 0x63,
  0x2F, 0x0B, 0x80, 0x44, 0x75, 0x99, 0x90, 0x45, 0xA8, 0x45, 0xAA, 0x80,
  0x44, 0x55, 0xEA, 0x90, 0xFE, 0x76, 0x96, 0x4C, 0x99, 0x20, 0x75, 0x99,
  0x90, 0x79, 0x99, 0xF0, 0x75, 0x99, 0xF8, 0x80, 0xF6, 0xDE, 0x48, 0x6A,
  0x48, 0xF8, 0x61, 0xF0, 0x4B, 0xA5, 0x30, 0xB6, 0xDE, 0xB6, 0xE8, 0xA6,
  0x9A, 0x76, 0x90, 0x55, 0x26, 0x90, 0x99, 0x55, 0x64, 0xC0, 0x72, 0x24,
  0xF0, 0x6A, 0xAA, 0xA0, 0x55, 0x5A, 0xA0, 0x55, 0x55, 0xA0, 0xBC };

const GFXglyph Exo2_ThinItalic_8pt7bGlyphs[] = {
  {     0,   1,   1,   2,    0,    0 },   // 0x20 ' '
  {     1,   1,   7,   2,    1,   -6 },   // 0x21 '!'
  {     2,   2,   2,   3,    1,   -6 },   // 0x22 '"'
  {     3,   6,   7,   6,    0,   -6 },   // 0x23 '#'
  {     9,   5,   9,   5,    0,   -7 },   // 0x24 '$'
  {    15,   6,   7,   8,    1,   -6 },   // 0x25 '%'
  {    21,   7,   7,   7,    0,   -6 },   // 0x26 '&'
  {    28,   1,   2,   2,    1,   -6 },   // 0x27 '''
  {    29,   2,   8,   3,    1,   -6 },   // 0x28 '('
  {    31,   3,   8,   3,    0,   -6 },   // 0x29 ')'
  {    34,   3,   3,   4,    1,   -6 },   // 0x2A '*'
  {    36,   3,   4,   5,    1,   -4 },   // 0x2B '+'
  {    38,   1,   2,   2,    0,    0 },   // 0x2C ','
  {    39,   3,   1,   4,    1,   -2 },   // 0x2D '-'
  {    40,   1,   1,   2,    0,    0 },   // 0x2E '.'
  {    41,   5,   7,   4,    0,   -6 },   // 0x2F '/'
  {    46,   4,   7,   5,    1,   -6 },   // 0x30 '0'
  {    50,   2,   7,   3,    1,   -6 },   // 0x31 '1'
  {    52,   5,   7,   5,    0,   -6 },   // 0x32 '2'
  {    57,   4,   7,   5,    0,   -6 },   // 0x33 '3'
  {    61,   5,   7,   5,    0,   -6 },   // 0x34 '4'
  {    66,   4,   7,   5,    0,   -6 },   // 0x35 '5'
  {    70,   4,   7,   5,    1,   -6 },   // 0x36 '6'
  {    74,   4,   7,   4,    1,   -6 },   // 0x37 '7'
  {    78,   4,   7,   6,    1,   -6 },   // 0x38 '8'
  {    82,   4,   7,   5,    1,   -6 },   // 0x39 '9'
  {    86,   1,   4,   2,    1,   -3 },   // 0x3A ':'
  {    87,   1,   5,   2,    0,   -3 },   // 0x3B ';'
  {    88,   3,   3,   5,    1,   -3 },   // 0x3C '<'
  {    90,   4,   3,   5,    1,   -3 },   // 0x3D '='
  {    92,   4,   3,   5,    0,   -3 },   // 0x3E '>'
  {    94,   3,   7,   4,    1,   -6 },   // 0x3F '?'
  {    97,   5,   7,   7,    1,   -6 },   // 0x40 '@'
  {   102,   5,   7,   5,    0,   -6 },   // 0x41 'A'
  {   107,   4,   7,   5,    1,   -6 },   // 0x42 'B'
  {   111,   4,   7,   5,    1,   -6 },   // 0x43 'C'
  {   115,   4,   7,   6,    1,   -6 },   // 0x44 'D'
  {   119,   4,   7,   5,    1,   -6 },   // 0x45 'E'
  {   123,   4,   7,   5,    1,   -6 },   // 0x46 'F'
  {   127,   4,   7,   6,    1,   -6 },   // 0x47 'G'
  {   131,   4,   7,   6,    1,   -6 },   // 0x48 'H'
  {   135,   1,   7,   2,    1,   -6 },   // 0x49 'I'
  {   136,   3,   7,   3,    0,   -6 },   // 0x4A 'J'
  {   139,   4,   7,   5,    1,   -6 },   // 0x4B 'K'
  {   143,   3,   7,   5,    1,   -6 },   // 0x4C 'L'
  {   146,   7,   7,   8,    0,   -6 },   // 0x4D 'M'
  {   153,   5,   7,   6,    1,   -6 },   // 0x4E 'N'
  {   158,   4,   7,   6,    1,   -6 },   // 0x4F 'O'
  {   162,   4,   7,   5,    1,   -6 },   // 0x50 'P'
  {   166,   4,   9,   6,    1,   -6 },   // 0x51 'Q'
  {   171,   4,   7,   5,    1,   -6 },   // 0x52 'R'
  {   175,   5,   7,   5,    0,   -6 },   // 0x53 'S'
  {   180,   4,   7,   5,    1,   -6 },   // 0x54 'T'
  {   184,   5,   7,   6,    1,   -6 },   // 0x55 'U'
  {   189,   5,   7,   5,    1,   -6 },   // 0x56 'V'
  {   194,   8,   7,   8,    1,   -6 },   // 0x57 'W'
  {   201,   5,   7,   5,    0,   -6 },   // 0x58 'X'
  {   206,   4,   7,   5,    1,   -6 },   // 0x59 'Y'
  {   210,   5,   7,   5,    0,   -6 },   // 0x5A 'Z'
  {   215,   3,  10,   3,    0,   -7 },   // 0x5B '['
  {   219,   3,   7,   4,    1,   -6 },   // 0x5C '\'
  {   222,   2,  10,   3,    0,   -7 },   // 0x5D ']'
  {   225,   3,   2,   4,    0,   -5 },   // 0x5E '^'
  {   226,   4,   1,   4,    0,    1 },   // 0x5F '_'
  {   227,   1,   1,   3,    1,   -5 },   // 0x60 '`'
  {   228,   3,   5,   5,    1,   -4 },   // 0x61 'a'
  {   230,   4,   7,   5,    0,   -6 },   // 0x62 'b'
  {   234,   4,   5,   4,    0,   -4 },   // 0x63 'c'
  {   237,   4,   7,   5,    1,   -6 },   // 0x64 'd'
  {   241,   4,   5,   5,    0,   -4 },   // 0x65 'e'
  {   244,   5,   9,   3,   -1,   -6 },   // 0x66 'f'
  {   250,   5,   7,   5,    0,   -4 },   // 0x67 'g'
  {   255,   4,   7,   5,    0,   -6 },   // 0x68 'h'
  {   259,   2,   7,   2,    0,   -6 },   // 0x69 'i'
  {   261,   2,   9,   2,    0,   -6 },   // 0x6A 'j'
  {   264,   4,   7,   4,    0,   -6 },   // 0x6B 'k'
  {   268,   1,   7,   2,    1,   -6 },   // 0x6C 'l'
  {   269,   7,   5,   8,    0,   -4 },   // 0x6D 'm'
  {   274,   4,   5,   5,    0,   -4 },   // 0x6E 'n'
  {   277,   4,   5,   5,    0,   -4 },   // 0x6F 'o'
  {   280,   4,   7,   5,    0,   -4 },   // 0x70 'p'
  {   284,   3,   7,   5,    1,   -4 },   // 0x71 'q'
  {   287,   3,   5,   3,    0,   -4 },   // 0x72 'r'
  {   289,   4,   5,   4,    0,   -4 },   // 0x73 's'
  {   292,   3,   7,   3,    0,   -6 },   // 0x74 't'
  {   295,   3,   5,   5,    1,   -4 },   // 0x75 'u'
  {   297,   3,   5,   5,    1,   -4 },   // 0x76 'v'
  {   299,   6,   5,   7,    1,   -4 },   // 0x77 'w'
  {   303,   4,   5,   5,    0,   -4 },   // 0x78 'x'
  {   306,   4,   7,   5,    0,   -4 },   // 0x79 'y'
  {   310,   4,   5,   4,    0,   -4 },   // 0x7A 'z'
  {   313,   2,  10,   3,    1,   -7 },   // 0x7B '{'
  {   316,   2,  10,   2,    0,   -7 },   // 0x7C '|'
  {   319,   2,  10,   3,    0,   -7 },   // 0x7D '}'
  {   322,   3,   2,   5,    1,   -3 } }; // 0x7E '~'

const GFXfont Exo2_ThinItalic_8pt7b = {
  (uint8_t  *)Exo2_ThinItalic_8pt7bBitmaps,
  (GFXglyph *)Exo2_ThinItalic_8pt7bGlyphs,
  0x20, 0x7E, 8 };//B

// Approx. 995 bytes
