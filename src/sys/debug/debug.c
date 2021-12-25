#include <stdio.h>

#include <cpctelera.h>
#include <sys/render/render.h>
#include <sys/input/input.h>

void sys_debug_waitKey() {
    sys_input_waitKey();
}

void sys_debug_info(const u8* str, u8 x, u8 y) {
    u8 buffer[40];
    cpct_memset(buffer, ' ', 40);
    buffer[39] = 0;

    _render_printMsg(buffer, 0, y, 0);
    _render_printMsg(str, x, y, 2);

    sys_debug_waitKey();
}

void sys_debug_char(u16 ascii, u8 x, u8 y) {
    _render_printChar(ascii, x, y, 2);
    sys_debug_waitKey();
}

void sys_debug_number(u8 num, u8 x, u8 y) {
   u8 str[4];   // string to write the value on
   sprintf(str, "%d", num);
   sys_debug_info(str, x, y);
}