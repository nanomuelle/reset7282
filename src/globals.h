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
#define ROOM_PEN        3

#define OUTS_X          69
#define OUTS_Y          ROOM_NAME_Y
#define OUTS_KERNEL     3   // separación entre caracteres en bytes
#define OUTS_PEN        1
#define OUTS_PEN_DARK   3

#define ROOM_TXT_Y      20
#define ROOM_TXT_X      8
#define ROOM_TXT_COLS   31
#define ROOM_TXT_PEN    1
#define ROOM_TXT_W      (2 + (ROOM_TXT_COLS * 8 / 4))
#define ROOM_TXT_H      100 // 70

#define ROOM_TXT_BOX_PADDING 4
#define ROOM_TXT_BOX_X  (ROOM_TXT_X - ROOM_TXT_BOX_PADDING)
#define ROOM_TXT_BOX_Y  (ROOM_TXT_Y - (2 * ROOM_TXT_BOX_PADDING))
#define ROOM_TXT_BOX_W  (ROOM_TXT_W + (2 * ROOM_TXT_BOX_PADDING))
#define ROOM_TXT_BOX_H  (ROOM_TXT_H + (4 * ROOM_TXT_BOX_PADDING))

#define PROMPT_X            0
#define PROMPT_Y            (200 - (2 * LINE_HEIGHT))
#define PROMPT_CHAR         ':'
#define PROMPT_CURSOR_CHAR  0x8F

#endif
