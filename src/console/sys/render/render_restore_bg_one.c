#include "render.h"

void csr_restore_bg_one(TEntity *entity) {
    u8* sprite_bg = entity->sprite_bg;
    u8 w = entity->render_w;
    u8 h = entity->render_h;
    u8* pmem = entity->pmem;
    if (sprite_bg) {
        cpct_drawSprite(sprite_bg, pmem, w, h);
    } else {
        cpct_drawSolidBox(pmem, 0, w, h);
    }
}