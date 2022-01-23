#include "render.h"

// void csr_draw_one(TEntity *entity) {
//     u8* pmem = cpct_getScreenPtr(
//         CPCT_VMEM_START, 
//         CSR_WORLD_TO_SCREEN_X(entity->world_x),
//         CSR_WORLD_TO_SCREEN_Y(entity->world_y)
//     );

//     // almacena la ultima pos de memoria en la que se ha pintado
//     entity->pmem = pmem;

//     // draw
//     cpct_drawSprite(entity->sprite, pmem, entity->render_w, entity->render_h);
// }

// void csr_draw_sprite(TEntity *entity) {
//     u8 x = CSR_PHY_TO_PX(entity->world_x);
//     u8 shift = x & 0b00000011;

//     csr_pp_drawSprite(
//         entity->pmem,
//         (u8 *)entity->sprite,
//         shift,
//         entity->render_w, // bytes
//         entity->render_h
//     );
// }

void csr_draw_one(TEntity *entity) {
    if (entity->sprite) {
        u8 x = CSR_PHY_TO_PX(entity->world_x);
        u8 shift = x & 0b00000011;

        csr_pp_drawSprite(
            entity->pmem,
            (u8 *)entity->sprite,
            shift,
            entity->render_w, // bytes
            entity->render_h
        );
    } else {
        csr_draw_box(entity, 2);
    }
}
