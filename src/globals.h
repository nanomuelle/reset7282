#ifndef RESET_GLOBALS
#define RESET_GLOBALS

#include <sys/debug/debug.h>

#define HI(x)  ((x) >> 8)
#define LO(x)  ((x) & 0xFF)

// RENDER
#define LINE_HEIGHT     8

#define ROOM_NAME_X     0
#define ROOM_NAME_Y     0
#define ROOM_NAME_W     51 // bytes
#define ROOM_PEN        2

#define OUTS_X          69
#define OUTS_Y          ROOM_NAME_Y
#define OUTS_KERNEL     3   // separación entre caracteres en bytes
#define OUTS_PEN        3
#define OUTS_PEN_DARK   2

#define ROOM_TXT_PEN    2

#define ROOM_TXT_X      ( 8)  // bytes
#define ROOM_TXT_Y      (16)  // pixels
#define ROOM_TXT_COLS   (32)  // CHARACTERS (8 BITS CADA UNO)
#define ROOM_TXT_W      (2 + (ROOM_TXT_COLS * 8 / 4)) // 2 + 26 x 2 = 54 bytes
#define ROOM_TXT_H      (96) // 16 * 6

// 320 - 256 = 64 pixels
//  80 -  64 = 16 bytes
//  40 -  32 =  8 characters

//   !          !         !         !            //
//   0123456789012345678901234567890123456789    //
// 0 ROOM NAME                                40 //
// 1    ┌--------------------------------┐    40 //
// 2    |********************************|    40 //
// 3
// 4

#define ROOM_TXT_BOX_PADDING 4
#define ROOM_TXT_BOX_X  (  8 ) // (ROOM_TXT_X - ROOM_TXT_BOX_PADDING)
#define ROOM_TXT_BOX_Y  ( 16 ) // (ROOM_TXT_Y - 4) // (ROOM_TXT_Y - (2 * ROOM_TXT_BOX_PADDING))
#define ROOM_TXT_BOX_W  ( 64 ) // (ROOM_TXT_W + (2 * ROOM_TXT_BOX_PADDING)) // 54 + 8 = 62 // 18 x 16
#define ROOM_TXT_BOX_H  ( 128 ) // (ROOM_TXT_H + (4 * ROOM_TXT_BOX_PADDING))

#define PROMPT_X            0
#define PROMPT_Y            (200 - (2 * LINE_HEIGHT))
#define PROMPT_CHAR         ':'
#define PROMPT_CURSOR_CHAR  0x8F
#define PROMPT_CHAR_PEN     2

#endif
