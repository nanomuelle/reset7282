#include <sys/render/render.h>

void _render_printMsg(const char* msg, u8 x, u8 y, u8 pen) {
   u8* video_memory_ptr;  // Pointer to video memory
   video_memory_ptr = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
   cpct_setDrawCharM1(pen, 0);
   cpct_drawStringM1(msg, video_memory_ptr);
}
