#ifndef RESET_GLOBALS
#define RESET_GLOBALS

#include <sys/debug/debug.h>

#define HI(x)  ((x) >> 8)
#define LO(x)  ((x) & 0xFF)

// RENDER
#define ROOM_TXT_Y      30
#define ROOM_TXT_X      8
#define ROOM_TXT_COLS   30
#define ROOM_TXT_PEN    1
#define ROOM_TXT_W      (2 + (ROOM_TXT_COLS * 8 / 4))
#define ROOM_TXT_H      70

#define ROOM_TXT_BOX_PADDING 4
#define ROOM_TXT_BOX_X  (ROOM_TXT_X - ROOM_TXT_BOX_PADDING)
#define ROOM_TXT_BOX_Y  (ROOM_TXT_Y - (2 * ROOM_TXT_BOX_PADDING))
#define ROOM_TXT_BOX_W  (ROOM_TXT_W + (2 * ROOM_TXT_BOX_PADDING))
#define ROOM_TXT_BOX_H  (ROOM_TXT_H + (4 * ROOM_TXT_BOX_PADDING))

#endif
