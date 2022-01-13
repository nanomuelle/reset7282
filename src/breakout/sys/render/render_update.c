#include <breakout/sys/render/render.h>
#include <breakout/man/entity/entity.h>
#include <sys/render/render.h>

#include <breakout/breakout.h>

void _breakout_sys_render_updateOne(TBreakoutEntity *entity) {
    u8* pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        BREAKOUT_WORLD_TO_SCREEN_X(entity->x), 
        BREAKOUT_WORLD_TO_SCREEN_Y(entity->y)
    );

    // delete
    if (pmem != entity->pmem) {
        cpct_drawSolidBox(
            entity->pmem, 
            BREAKOUT_SYS_RENDER_BG_COLOR, 
            entity->render_w, 
            entity->render_h
        );

        // almacena la ultima pos de memoria en la que se ha pintado
        entity->pmem = pmem;

    }

    // paint
    cpct_drawSprite(entity->sprite, pmem, entity->render_w, entity->render_h);
}

void breakout_sys_render_update(void) {
    breakout_man_entity_forEach(_breakout_sys_render_updateOne);
}