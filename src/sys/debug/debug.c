#include <stdio.h>

#include <cpctelera.h>
#include <sys/render/render.h>
#include <sys/input/input.h>

void sys_debug_waitKey() {
    sys_input_waitKey();
}

u8 buffer[40];
u8 str_buffer[40];

void sys_debug_info_at(const u8* str, u8 x, u8 y) {
    cpct_memset(buffer, ' ', 40);
    buffer[39] = 0;
    
    _render_printMsg(buffer, 0, y, 0);
    _render_printMsg(str, x, y, 2);

    sys_debug_waitKey();
}

void sys_debug_char_at(u16 ascii, u8 x, u8 y) {
    _render_printChar(ascii, x, y, 2);
    sys_debug_waitKey();
}

void sys_debug_number_at(u16 num, u8 x, u8 y) {
   sprintf(str_buffer, "%u", num);
   sys_debug_info_at(str_buffer, x, y);
}

void sys_debug_info(const u8* str) {
    sys_debug_info_at(str, 0, 0);
}

void sys_debug_char(u16 ascii) {
    sys_debug_char_at(ascii, 0, 0);
}

void sys_debug_number(u16 num) {
   sys_debug_number_at(num, 0, 0);
}