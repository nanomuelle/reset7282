#include "ers.h"
#include <sys/render/render.h>

void ers_init(void) {
    u8 bg_color = cpct_px2byteM1(1, 1, 1, 1);

    ers_init_mask_table();

    _render_clearBox(
        ERS_OFFSET_X_BYTES,
        ERS_OFFSET_Y_BYTES,
        ERS_PX_TO_BYTES(ERS_SCREEN_W),
        ERS_SCREEN_H,
        bg_color
    );
    
}