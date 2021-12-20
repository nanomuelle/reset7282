#ifndef RESET_SYS_DEBUG
#define RESET_SYS_DEBUG

extern void sys_debug_infoString(const u8* str, u8 x, u8 y);
extern void sys_debug_infoChar(const u16 ascii, u8 x, u8 y);
extern void sys_debug_waitKey(void);

#endif