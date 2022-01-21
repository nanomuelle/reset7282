#include "render.h"

void csr_capture_one_bg(TEntity *e) {
    u8* sprite_bg = e->sprite_bg;
    if (sprite_bg) {
        cpct_getScreenToSprite(
            e->pmem,
            sprite_bg,
            e->render_w,
            e->render_h
        );
    }
}