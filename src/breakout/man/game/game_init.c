#include "game.h"
#include <breakout/sys/render/render.h>

#include <assets/breakout_ball.h>
#include <assets/breakout_paddel.h>

#include <man/objs/objs.h>
#include <breakout/man/bricks/bricks.h>

const u8 _breakout_man_game_ball_bg[G_SPRITE_BREAKOUT_BALL_W * G_SPRITE_BREAKOUT_BALL_H];
const u8 _breakout_man_game_paddel_bg[G_SPRITE_BREAKOUT_PADDEL_W * G_SPRITE_BREAKOUT_PADDEL_H];

const TEntity m_breakout_entity_ballTemplate = {
    BREAKOUT_ENTITY_ID_BALL,

    ENTITY_STATE_DEFAULT,
    ENTITY_COMPONENT_PHYSICS | ENTITY_COMPONENT_RENDER | ENTITY_COMPONENT_AI,

    // physics component
    BREAKOUT_WORLD_BALL_X,
    BREAKOUT_WORLD_BALL_Y,
    BREAKOUT_WORLD_BALL_W,
    BREAKOUT_WORLD_BALL_H,
    BREAKOUT_WORLD_BALL_VX,
    BREAKOUT_WORLD_BALL_VY,

    // render component
    0xc000,                     // pmem
    HI(BREAKOUT_WORLD_BALL_W),  // w render
    HI(BREAKOUT_WORLD_BALL_H),  // h render
    g_sprite_breakout_ball,     // sprite ptr
    _breakout_man_game_ball_bg,

    // ai component
    0x0000, // no ai
};

const TEntity m_breakout_entity_paddelTemplate = {
    BREAKOUT_ENTITY_ID_PADDEL,

    ENTITY_STATE_DEFAULT,
    ENTITY_COMPONENT_PHYSICS | ENTITY_COMPONENT_RENDER | ENTITY_COMPONENT_AI,

    // physics component
    BREAKOUT_WORLD_PADDEL_X,
    BREAKOUT_WORLD_PADDEL_Y,
    BREAKOUT_WORLD_PADDEL_W,
    BREAKOUT_WORLD_PADDEL_H,
    0,
    0,

    // render component
    0xc000,                         // pmem
    HI(BREAKOUT_WORLD_PADDEL_W),    // w render
    HI(BREAKOUT_WORLD_PADDEL_H),    // h render
    g_sprite_breakout_paddel,       // sprite ptr
    _breakout_man_game_paddel_bg,

    // ai component
    breakout_man_game_behavior_userInput, // user input
};

void m_breakout_man_game_create_entities(void) {
    TEntity* entity;
    u8* pmem;

    //
    // ball
    //
    entity = man_entity_create();
    cpct_memcpy(entity, &m_breakout_entity_ballTemplate, sizeof(TEntity));
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        CSR_WORLD_TO_SCREEN_X(entity->world_x), 
        CSR_WORLD_TO_SCREEN_Y(entity->world_y)
    );
    csp_addEntity(entity); // add entity to physics system

    //
    // paddel
    //
    entity = man_entity_create();
    cpct_memcpy(entity, &m_breakout_entity_paddelTemplate, sizeof(TEntity));
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        CSR_WORLD_TO_SCREEN_X(entity->world_x), 
        CSR_WORLD_TO_SCREEN_Y(entity->world_y)
    );
    csp_addEntity(entity); // add entity to physics system

    //
    // bricks
    //
    {
        i16 fromY = CSP_WORLD_MIN_Y + (2 * BREAKOUT_WORLD_BRICK_H);
        i16 toY = fromY + (2 * BREAKOUT_WORLD_BRICK_H);

        for (i16 y = fromY; y <= toY ; y += BREAKOUT_WORLD_BRICK_H) {
            i16 fromX = CSP_WORLD_MIN_X + (2 * BREAKOUT_WORLD_BRICK_W);
            i16 toX   = CSP_WORLD_MAX_X - (2 * BREAKOUT_WORLD_BRICK_W);
            for (i16 x = fromX; x <= toX ; x += BREAKOUT_WORLD_BRICK_W) {
                man_bricks_create(x, y);
            }
        }
    }
}

void breakout_man_game_init(void) {
    TEntity *entity;

    // init systems
    csp_init();
    csr_init();

    // init managers
    man_entity_init();
    man_bricks_init();

    // create initial entities
    m_breakout_man_game_create_entities();
    breakout_sys_render_init();
}