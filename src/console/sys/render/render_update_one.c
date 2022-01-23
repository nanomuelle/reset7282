#include "render.h"

// #include <sys/render/render.h>
#include<stdio.h>
void csr_update_one(TEntity *entity) {
    // si ha cambiado de pos, repintamos la entidad
    if (entity->state & CME_ENTITY_STATE_MOVED) {
        u8* pmem = csr_getScreenPtr(
            CSR_PHY_TO_PX(entity->world_x),
            CSR_PHY_TO_PX(entity->world_y)
        );

        // actualiza la pos de memoria para pintar
        entity->pmem = pmem;

        // capture bg
        csr_capture_one_bg(entity);

        // draw sprite
        csr_draw_one(entity);

        // reset moved state
        // cme_resetStateMoved(entity);
    }
}