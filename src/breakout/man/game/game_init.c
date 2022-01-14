#include <breakout/man/game/game.h>
#include <man/entity/entity.h>
#include <breakout/sys/render/render.h>

#include <assets/breakout_ball.h>
#include <assets/breakout_paddel.h>
#include <assets/breakout_yellow_brick.h>

#include <man/objs/objs.h>
#include <sys/debug/debug.h>

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

    // ai component
    0 // no ai
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
    0xc000,                     // pmem
    HI(BREAKOUT_WORLD_PADDEL_W),  // w render
    HI(BREAKOUT_WORLD_PADDEL_H),  // h render
    g_sprite_breakout_paddel,     // sprite ptr

    // ai component
    breakout_man_game_behavior_userInput // user input
};
const TEntity m_breakout_entity_brickTemplate = {
    BREAKOUT_ENTITY_ID_BRICK,

    ENTITY_STATE_DEFAULT,
    ENTITY_COMPONENT_PHYSICS | ENTITY_COMPONENT_RENDER | ENTITY_COMPONENT_AI,

    // physics component
    0,  // x
    0,  // y
    BREAKOUT_WORLD_BRICK_W,
    BREAKOUT_WORLD_BRICK_H,
    0,  // vx
    0,  // vy

    // render component
    0xc000,                     // pmem
    HI(BREAKOUT_WORLD_BRICK_W),  // w render
    HI(BREAKOUT_WORLD_BRICK_H),  // h render
    g_sprite_breakout_yellow_brick,     // sprite ptr

    // ai component
    0 // no ai
};

void _init_breakout_entities(void) {
    TEntity* entity;

    man_entity_init();

    // ball
    entity = man_entity_create();
    cpct_memcpy(entity, &m_breakout_entity_ballTemplate, sizeof(TEntity));

    entity = man_entity_create();
    cpct_memcpy(entity, &m_breakout_entity_paddelTemplate, sizeof(TEntity));

    {
        i16 fromY = BREAKOUT_WORLD_MIN_Y + (1 * BREAKOUT_WORLD_BRICK_H);
        i16 toY = fromY + (3 * BREAKOUT_WORLD_BRICK_H);
        i16 iY = BREAKOUT_WORLD_BRICK_H;

        for (i16 y = fromY; y <= toY ; y += iY) {
            i16 fromX = BREAKOUT_WORLD_MIN_X + (2 * BREAKOUT_WORLD_BRICK_W);
            i16 toX   = BREAKOUT_WORLD_MAX_X - (3 * BREAKOUT_WORLD_BRICK_W);
            i16 iX    = BREAKOUT_WORLD_BRICK_W;
             for (i16 x = fromX; x <= toX ; x += iX) {
                entity = man_entity_create();
                cpct_memcpy(entity, &m_breakout_entity_brickTemplate, sizeof(TEntity));
                entity->world_x = x;
                entity->world_y = y;
            }
        }
    }
}

void breakout_man_game_init(void) {
    _init_breakout_entities();
    // breakout_man_score_init();

    breakout_sys_render_init();
    // breakout_sys_input_init();
    // breakout_sys_ai_init();
    // breakout_sys_physics_init();
}