#include "render.h"
#include <sys/render/render.h>

void m_csr_restoreBackground(TEntity *entity) {
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

void m_csr_updateOne(TEntity *entity) {
    if (entity->state & CME_ENTITY_STATE_DEAD) {
        m_csr_restoreBackground(entity);
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
            m_csr_restoreBackground(entity);

            // capture bg
            cpct_getScreenToSprite(pmem, sprite_bg, w, h);

            // paint
            cpct_drawSprite(entity->sprite, pmem, w, h);

            // almacena la ultima pos de memoria en la que se ha pintado
            entity->pmem = pmem;
        }
    }
}

void csr_update(void) {
    cme_forAll(m_csr_updateOne);
}