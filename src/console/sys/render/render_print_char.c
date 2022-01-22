#include "render.h"

void csr_printChar(u16 ascii, u8 x, u8 y, u8 pen) {
   u8* video_memory_ptr = csr_getScreenPtr(x, y);
   cpct_setDrawCharM1(pen, 0);
   cpct_drawCharM1(video_memory_ptr, ascii);
}