#include <breakout/sys/render/render.h>
#include <man/entity/entity.h>
#include <sys/render/render.h>

#include <breakout/breakout.h>

void _breakout_sys_render_restoreBg(TEntity *entity) {
    cpct_drawSprite(
        entity->sprite_bg,
        entity->pmem,
        entity->render_w,
        entity->render_h
    );
}

void _breakout_sys_render_updateOne(TEntity *entity) {
    if (ENTITY_STATE_DEAD == (entity->state & ENTITY_STATE_DEAD)) {
        cpct_drawSprite(
            entity->sprite_bg,
            entity->pmem,
            entity->render_w,
            entity->render_h
        );

        // TODO: esto no va aqui, eliminar la entidad debe hacerse en breakout_man_game
        // breakout_man_entity_delete(entity);
        // man_entity_destroy(entity);
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
            u8 w = entity->render_w;
            u8 h = entity->render_h;
            u8* sprite_bg = entity->sprite_bg;

            // restore bg
            cpct_drawSprite(sprite_bg, entity->pmem, w, h);

            // capture bg
            cpct_getScreenToSprite(pmem, sprite_bg, w, h);

            // paint
            cpct_drawSprite(entity->sprite, pmem, w, h);

            // almacena la ultima pos de memoria en la que se ha pintado
            entity->pmem = pmem;
        }
    }
}

void breakout_sys_render_update(void) {
    man_entity_forAll(_breakout_sys_render_updateOne);
}