#include "render.h"
#include <sys/render/render.h>

void csr_init(void) {
    u8 color = cpct_px2byteM1(0, 0, 0, 0);

    csr_init_mask_table();

    // cpct_setBlendMode(CPCT_BLEND_OR);
    _render_clearBox(
        ROOM_TXT_BOX_X,
        ROOM_TXT_BOX_Y,
        ROOM_TXT_BOX_W,
        ROOM_TXT_BOX_H,
        color
    );
}