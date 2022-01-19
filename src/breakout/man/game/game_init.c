#include <breakout/man/game/game.h>
#include <man/entity/entity.h>
#include <breakout/sys/render/render.h>

#include <assets/breakout_ball.h>
#include <assets/breakout_paddel.h>

#include <man/objs/objs.h>
#include <sys/debug/debug.h>
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

void _init_breakout_entities(void) {
    TEntity* entity;
    u8* pmem;

    man_entity_init();

    // ball
    entity = man_entity_create();
    cpct_memcpy(entity, &m_breakout_entity_ballTemplate, sizeof(TEntity));
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        BREAKOUT_WORLD_TO_SCREEN_X(entity->world_x), 
        BREAKOUT_WORLD_TO_SCREEN_Y(entity->world_y)
    );

    // paddel
    entity = man_entity_create();
    cpct_memcpy(entity, &m_breakout_entity_paddelTemplate, sizeof(TEntity));
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        BREAKOUT_WORLD_TO_SCREEN_X(entity->world_x), 
        BREAKOUT_WORLD_TO_SCREEN_Y(entity->world_y)
    );

    // bricks
    {
        i16 fromY = BREAKOUT_WORLD_MIN_Y + (2 * BREAKOUT_WORLD_BRICK_H);
        i16 toY = fromY + (2 * BREAKOUT_WORLD_BRICK_H);

        for (i16 y = fromY; y <= toY ; y += BREAKOUT_WORLD_BRICK_H) {
            i16 fromX = BREAKOUT_WORLD_MIN_X + (2 * BREAKOUT_WORLD_BRICK_W);
            i16 toX   = BREAKOUT_WORLD_MAX_X - (2 * BREAKOUT_WORLD_BRICK_W);
            for (i16 x = fromX; x <= toX ; x += BREAKOUT_WORLD_BRICK_W) {
                man_bricks_create(x, y);
                // entity = man_entity_create();
                // cpct_memcpy(entity, &m_breakout_entity_brickTemplate, sizeof(TEntity));
                // entity->world_x = x;
                // entity->world_y = y;
                // entity->sprite_bg = bg;
                // entity->pmem = cpct_getScreenPtr(
                //     CPCT_VMEM_START, 
                //     BREAKOUT_WORLD_TO_SCREEN_X(x), 
                //     BREAKOUT_WORLD_TO_SCREEN_Y(y)
                // );

                // bg += BREAKOUT_WORLD_BRICK_W * BREAKOUT_WORLD_BRICK_H;
            }
        }
    }
}

void breakout_man_game_init(void) {
    TEntity *entity;

    man_bricks_init();
    _init_breakout_entities();

    // breakout_man_score_init();

    breakout_sys_render_init();
    // breakout_sys_input_init();
    // breakout_sys_ai_init();
    // breakout_sys_physics_init();
}