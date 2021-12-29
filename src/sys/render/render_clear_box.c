#include <sys/render/render.h>

void _render_clearBox(u8 x, u8 y, u8 w, u8 h) {
    if ( w > 0 && w <= 64 ) {
        cpct_drawSolidBox(
            cpct_getScreenPtr(CPCT_VMEM_START, x, y),
            0,
            w, h
        );
        return;
    };

    cpct_drawSolidBox(
        cpct_getScreenPtr(CPCT_VMEM_START, x, y),
        0,
        64, h
    );
    _render_clearBox(x + 64, y, w - 64, h);
}
