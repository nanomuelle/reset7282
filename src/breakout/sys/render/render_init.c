#include <breakout/sys/render/render.h>
#include <sys/render/render.h>

#include <breakout/breakout.h>
#include <man/entity/entity.h>

void _breakout_sys_render_one(TEntity *entity) {
    u8* pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        BREAKOUT_WORLD_TO_SCREEN_X(entity->world_x), 
        BREAKOUT_WORLD_TO_SCREEN_Y(entity->world_y)
    );

    // almacena la ultima pos de memoria en la que se ha pintado
    entity->pmem = pmem;

    // paint
    cpct_drawSprite(entity->sprite, pmem, entity->render_w, entity->render_h);
}

void breakout_sys_render_init(void) {
    _render_clearRoomTxt();
    man_entity_forAll(_breakout_sys_render_one);
}