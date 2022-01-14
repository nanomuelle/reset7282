#ifndef RESET_SYS_DEBUG
#define RESET_SYS_DEBUG
#define RESET_ASSERTS_TRUE

#include <cpctelera.h>

extern void sys_debug_info(const u8* str, u8 x, u8 y);
extern void sys_debug_char(const u16 ascii, u8 x, u8 y);
extern void sys_debug_number(u8 num, u8 x, u8 y);
extern void sys_debug_waitKey(void);

#endif