#include <breakout/sys/render/render.h>
#include <man/entity/entity.h>
#include <sys/render/render.h>

#include <breakout/breakout.h>

void _breakout_sys_render_updateOne(TEntity *entity) {
    if (ENTITY_STATE_DEAD == (entity->state & ENTITY_STATE_DEAD)) {
        cpct_drawSolidBox(
            entity->pmem, 
            BREAKOUT_SYS_RENDER_BG_COLOR, 
            entity->render_w, 
            entity->render_h
        );
        // TODO: esto no va aqui, elminar la entidad debe hacerse en breakout_man_game
        // breakout_man_entity_delete(entity);
        man_entity_destroy(entity);
        return;
    }

    {
        u8* pmem = cpct_getScreenPtr(
            CPCT_VMEM_START, 
            BREAKOUT_WORLD_TO_SCREEN_X(entity->world_x), 
            BREAKOUT_WORLD_TO_SCREEN_Y(entity->world_y)
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

            // paint
            cpct_drawSprite(entity->sprite, pmem, entity->render_w, entity->render_h);
        }
    }
}

void breakout_sys_render_update(void) {
    man_entity_forAll(_breakout_sys_render_updateOne);
}