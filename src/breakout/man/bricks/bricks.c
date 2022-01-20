#include "bricks.h"
#include <breakout/sys/render/render.h>

const u8 m_man_bricks_bg_buffer[MAX_BRICKS * G_SPRITE_BREAKOUT_MEDIUM_BRICK_W * G_SPRITE_BREAKOUT_MEDIUM_BRICK_H];
u8 m_man_bricks_num;
u8* m_man_bricks_next_bg_free;

const TEntity m_man_bricks_brick_template = {
    BREAKOUT_ENTITY_ID_BRICK,

    CME_ENTITY_STATE_DEFAULT,
    CME_ENTITY_COMPONENT_PHYSICS | CME_ENTITY_COMPONENT_RENDER | CME_ENTITY_COMPONENT_AI,

    // physics component
    0,  // x
    0,  // y
    BREAKOUT_WORLD_BRICK_W,
    BREAKOUT_WORLD_BRICK_H,
    0,  // vx
    0,  // vy

    // render component
    0x0000,                         // pmem
    HI(BREAKOUT_WORLD_BRICK_W),     // w render
    HI(BREAKOUT_WORLD_BRICK_H),     // h render
    g_sprite_breakout_medium_brick, // sprite ptr
    0x0000,

    // ai component
    0x0000, // no ai
};

void man_bricks_init(void) {
    m_man_bricks_num = 0;
    m_man_bricks_next_bg_free = m_man_bricks_bg_buffer;
}

TEntity* man_bricks_create(i16 x, i16 y) {
    TEntity *entity = cme_create();
    cpct_memcpy(entity, &m_man_bricks_brick_template, sizeof(TEntity));

    entity->world_x = x;
    entity->world_y = y;
    entity->sprite_bg = m_man_bricks_next_bg_free;
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START,
        CSR_WORLD_TO_SCREEN_X(x),
        CSR_WORLD_TO_SCREEN_Y(y)
    );

    ++m_man_bricks_num;
    m_man_bricks_next_bg_free += G_SPRITE_BREAKOUT_MEDIUM_BRICK_W * G_SPRITE_BREAKOUT_MEDIUM_BRICK_H;

    return entity;
}