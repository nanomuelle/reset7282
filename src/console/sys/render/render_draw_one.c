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

void csr_draw_sprite(TEntity *entity) {
    u16 x = CSR_WORLD_TO_SCREEN_X(entity->world_x);
    u8 frame = x & 0b00000011;
    u8 w = entity->render_w; // bytes
    u8* pmem = csr_getScreenPtr(
        x,
        CSR_WORLD_TO_SCREEN_Y(entity->world_y)
    );

    // almacena la ultima pos de memoria en la que se ha pintado
    entity->pmem = pmem;

    // if (frame == 0) {
    //     --w;
    // }
    // draw
    // cpct_drawSprite(entity->sprite[frame], pmem, entity->render_w, entity->render_h);
    // cpct_drawSprite(entity->sprite[frame], pmem, 2, 4);
    // cpct_drawSprite(entity->sprite[frame], pmem, w, entity->render_h);
    cpct_drawSpriteBlended(pmem, entity->render_h, w, entity->sprite[frame]);
}

void csr_draw_one(TEntity *entity) {
    if (entity->sprite) {
        csr_draw_sprite(entity);
    } else {
        csr_draw_box(entity, 2);
    }
}
