#include <sys/render/render.h>

void _render_clearBox(u8 x, u8 y, u8 w, u8 h) {
    cpct_drawSolidBox(
        cpct_getScreenPtr(CPCT_VMEM_START, x, y),
        cpct_px2byteM1(0, 0, 0, 0),
        w, h
    );
}
