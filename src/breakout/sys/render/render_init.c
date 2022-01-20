#include <breakout/sys/render/render.h>
#include <sys/render/render.h>
#include <breakout/breakout.h>
#include <assets/breakout_bg.h>

void m_breakout_sys_render_capture_one_bg(TEntity *e) {
    cpct_getScreenToSprite(
        e->pmem,
        e->sprite_bg,
        e->render_w,
        e->render_h
    );
}

void m_breakout_sys_render_bg() {
    i16 y = CSR_WORLD_TO_SCREEN_Y(CSP_WORLD_MIN_Y);

    for (u8 row = ROOM_TXT_BOX_H / G_SPRITE_BREAKOUT_BG_0_H; row > 0; --row) {
        u8 x = CSR_WORLD_TO_SCREEN_X(CSP_WORLD_MIN_X);
        u8* pmem = cpct_getScreenPtr(CPCT_VMEM_START, x, y);

        for (u8 col = ROOM_TXT_BOX_W / G_SPRITE_BREAKOUT_BG_0_W; col > 0; --col) {
            u8* bg = (row + col) & 0x03 ? g_sprite_breakout_bg_1 : g_sprite_breakout_bg_0;
            cpct_drawSprite(bg, pmem, G_SPRITE_BREAKOUT_BG_0_W, G_SPRITE_BREAKOUT_BG_0_H);
            pmem += G_SPRITE_BREAKOUT_BG_0_W;
        }

        y += G_SPRITE_BREAKOUT_BG_0_H;
    }
}

void m_breakout_sys_render_one(TEntity *entity) {
    u8* pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        CSR_WORLD_TO_SCREEN_X(entity->world_x),
        CSR_WORLD_TO_SCREEN_Y(entity->world_y)
    );

    // almacena la ultima pos de memoria en la que se ha pintado
    entity->pmem = pmem;

    // draw
    cpct_drawSprite(entity->sprite, pmem, entity->render_w, entity->render_h);
}

void breakout_sys_render_init(void) {
    m_breakout_sys_render_bg();
    man_entity_forAll(m_breakout_sys_render_capture_one_bg);
    man_entity_forAll(m_breakout_sys_render_one);
}