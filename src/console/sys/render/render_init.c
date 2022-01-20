#include "render.h"
#include <sys/render/render.h>

// void m_consola_sys_render_capture_one_bg(TEntity *entity) {
//     cpct_getScreenToSprite(
//         entity->pmem,
//         entity->sprite_bg,
//         entity->render_w,
//         entity->render_h
//     );
// }

// void m_csr_one(TEntity *entity) {
//     u8* pmem = cpct_getScreenPtr(
//         CPCT_VMEM_START, 
//         CSR_WORLD_TO_SCREEN_X(entity->world_x), 
//         CSR_WORLD_TO_SCREEN_Y(entity->world_y)
//     );

//     // almacena la ultima pos de memoria en la que se ha pintado
//     entity->pmem = pmem;

//     // paint
//     cpct_drawSprite(entity->sprite, pmem, entity->render_w, entity->render_h);
// }

void csr_init(void) {
    _render_clearBox(
        ROOM_TXT_BOX_X,
        ROOM_TXT_BOX_Y,
        ROOM_TXT_BOX_W,
        ROOM_TXT_BOX_H
    );
}