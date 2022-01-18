#include <breakout/sys/render/render.h>
#include <sys/render/render.h>

#include <breakout/breakout.h>
#include <man/entity/entity.h>

#include <assets/breakout_bg.h>

void _breakout_sys_render_capture_one_bg(TEntity *entity) {
    cpct_getScreenToSprite(
        entity->pmem,
        entity->sprite_bg,
        entity->render_w,
        entity->render_h
    );
}

void _breakout_sys_render_bg() {
    i16 y = BREAKOUT_WORLD_TO_SCREEN_Y(BREAKOUT_WORLD_MIN_Y);
    u8* pmem;
    u8* bg;
    for (u8 row = ROOM_TXT_BOX_H / G_SPRITE_BREAKOUT_BG_0_H; row > 0; --row) {
        pmem = cpct_getScreenPtr(
            CPCT_VMEM_START,
            BREAKOUT_WORLD_TO_SCREEN_X( BREAKOUT_WORLD_MIN_X ),
            y
        );

        for (u8 col = ROOM_TXT_BOX_W / G_SPRITE_BREAKOUT_BG_0_W; col > 0; --col) {
            bg = (row + col) & 0x03 ? g_sprite_breakout_bg_1 : g_sprite_breakout_bg_0;
            cpct_drawSprite(bg, pmem, G_SPRITE_BREAKOUT_BG_0_W, G_SPRITE_BREAKOUT_BG_0_H);
            pmem += G_SPRITE_BREAKOUT_BG_0_W;
        }

        y += G_SPRITE_BREAKOUT_BG_0_H;
    }

    pmem = cpct_getScreenPtr(
        CPCT_VMEM_START,
        BREAKOUT_WORLD_TO_SCREEN_X(BREAKOUT_WORLD_MIN_X),
        BREAKOUT_WORLD_TO_SCREEN_Y(BREAKOUT_WORLD_MIN_Y)
    );

    // cpct_getScreenToSprite(pmem, sprite_bg, ROOM_TXT_BOX_W, ROOM_TXT_BOX_H);
    // cpct_getScreenToSprite(pmem, sprite_bg, ROOM_TXT_BOX_W, 10);

}

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
    _breakout_sys_render_bg();

    man_entity_forAll(_breakout_sys_render_capture_one_bg);
    man_entity_forAll(_breakout_sys_render_one);
}