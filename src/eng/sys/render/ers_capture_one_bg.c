#include "ers.h"

void ers_capture_one_bg(TEEM_entity *e) {
    u8* sprite_bg = e->render.sprite_bg;
    if (sprite_bg) {
        cpct_getScreenToSprite(
            e->render.pmem,
            sprite_bg,
            e->render.w,
            e->render.h
        );
    }
}