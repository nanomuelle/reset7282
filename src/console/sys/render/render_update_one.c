#include "render.h"

// #include <sys/render/render.h>
#include<stdio.h>
void csr_update_one(TEntity *entity) {
    // if (entity->state & CME_ENTITY_STATE_DEAD) {
    //     csr_restore_bg_one(entity);
    //     return;
    // }

    // si ha cambiado de pos, repintamos la entidad
    if (entity->state & CME_ENTITY_STATE_MOVED) {
        u8* pmem = csr_getScreenPtr(
            CSR_WORLD_TO_SCREEN_X(entity->world_x),
            CSR_WORLD_TO_SCREEN_Y(entity->world_y)
        );

        // actualiza la pos de memoria para pintar
        entity->pmem = pmem;

        // capture bg
        csr_capture_one_bg(entity);

        // paint
        csr_draw_one(entity);

        cme_resetStateMoved(entity);
    }
}