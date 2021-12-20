#include <cpctelera.h>
#include <sys/render/render.h>
#include <sys/input/input.h>

void sys_debug_waitKey() {
    sys_input_waitKey();
}

void sys_debug_infoString(const u8* str, u8 x, u8 y) {
    u8 buffer[40];
    cpct_memset(buffer, ' ', 40);
    buffer[39] = 0;

    printMsg(buffer, 0, y, 0);
    printMsg(str, x, y, 1);
}

void sys_debug_infoChar(u16 ascii, u8 x, u8 y) {
    printChar(ascii, x, y);
}