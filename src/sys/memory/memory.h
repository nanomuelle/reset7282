#ifndef RESET_SYS_MEM
#define RESET_SYS_MEN

#include <cpctelera.h>

// PUBLIC
extern void sys_mem_memcpy(void *to, const void *from, u16 size) __z88dk_callee;
extern void sys_mem_memcpyRtl(void *to, const void *from, u16 size) __z88dk_callee;

#endif