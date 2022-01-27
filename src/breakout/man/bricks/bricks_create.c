#include "bricks.h"

TEEM_entity* man_bricks_create(u16 world_x, u16 world_y) {
    TEEM_entity *e = eem_create();
    cpct_memcpy(e, &m_man_bricks_brick_template, sizeof(TEEM_entity));

    e->tr.world.x = world_x;
    e->tr.world.x2 = world_x + e->tr.world.w;
    e->tr.world.y = world_y;
    e->tr.world.y2 = world_y + e->tr.world.h;
    e->render.sprite_bg = m_man_bricks_next_bg_free;
    e->render.pmem = ers_get_screen_ptr(
        e->tr.screen.x,
        e->tr.screen.y
    );

    ++m_man_bricks_num;
    m_man_bricks_next_bg_free += G_SPR_BRK_BRICK_M1_0_W * G_SPR_BRK_BRICK_M1_0_H;

    return e;
}