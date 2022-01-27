#include "ers.h"

void ers_capture_one_bg(TEEM_entity *e) {
    u8* sprite_bg = e->render.sprite_bg;
    u8 w = e->render.w;
    if (sprite_bg) {
        if (e->render.shift == 0) {
            --w;
        }

        cpct_getScreenToSprite(
            e->render.pmem,
            sprite_bg,
            w,
            e->render.h
        );
    }
}