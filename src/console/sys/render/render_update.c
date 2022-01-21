#include "render.h"
#include <sys/render/render.h>

void m_csr_updateOne(TEntity *entity) {
    if (entity->state & CME_ENTITY_STATE_DEAD) {
        csr_restore_bg_one(entity);
        return;
    }

    {
        u8* pmem = cpct_getScreenPtr(
            CPCT_VMEM_START, 
            CSR_WORLD_TO_SCREEN_X(entity->world_x), 
            CSR_WORLD_TO_SCREEN_Y(entity->world_y)
        );

        // si ha cambiado de pos, repintamos la entidad
        if (pmem != entity->pmem) {
            u8 w = entity->render_w;
            u8 h = entity->render_h;
            u8* sprite_bg = entity->sprite_bg;

            // restore bg
            csr_restore_bg_one(entity);

            // actualiza la pos de memoria para pintar
            entity->pmem = pmem;

            // capture bg
            csr_capture_one_bg(entity);
            // cpct_getScreenToSprite(pmem, sprite_bg, w, h);

            // paint
            csr_draw_one(entity);
            // cpct_drawSprite(entity->sprite, pmem, w, h);

        }
    }
}

void csr_update(void) {
    cme_forAll(m_csr_updateOne);
}