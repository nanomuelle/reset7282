#include "game.h"
#include <eng/eng.h>

#include <breakout/sys/render/render.h>

#include <assets/breakout_ball_m1.h>
#include <assets/breakout_paddel.h>

#include <man/objs/objs.h>
#include <breakout/man/bricks/bricks.h>

const u8 _breakout_man_game_ball_bg[G_SPR_BRK_BALL_M1_0_W * G_SPR_BRK_BALL_M1_0_H];
const u8 _breakout_man_game_paddel_bg[G_SPR_BRK_PADDEL_W * G_SPR_BRK_PADDEL_H];

const TEntity m_breakout_entity_ballTemplate = {
    BREAKOUT_ENTITY_ID_BALL,

    CME_ENTITY_STATE_DEFAULT,
    CME_ENTITY_COMPONENT_PHYSICS | CME_ENTITY_COMPONENT_RENDER | CME_ENTITY_COMPONENT_AI,

    // physics component
    BREAKOUT_WORLD_BALL_X,
    BREAKOUT_WORLD_BALL_Y,
    BREAKOUT_WORLD_BALL_W,
    BREAKOUT_WORLD_BALL_H,
    0, // CSP_PX_TO_WORLD(1), //  BREAKOUT_WORLD_BALL_VX,
    0, // BREAKOUT_WORLD_BALL_VY,

    // render component
    0xc000,                     // pmem
    HI(BREAKOUT_WORLD_BALL_W),  // w render
    HI(BREAKOUT_WORLD_BALL_H),  // h render
    g_spr_brk_ball_m1_frames,     // sprite ptr
    _breakout_man_game_ball_bg,

    // anim component
    4,          // total num of frames
    0,          // index of the current frame
    0x0000,     // g_spr_brk_ball_anim,     // array of ptr to sprite ptrs

    // ai component
    breakout_man_game_behavior_userInput, // 0x0000, // no ai
};

const TEntity m_breakout_entity_paddelTemplate = {
    BREAKOUT_ENTITY_ID_PADDEL,

    CME_ENTITY_STATE_DEFAULT,
    CME_ENTITY_COMPONENT_PHYSICS | CME_ENTITY_COMPONENT_RENDER | CME_ENTITY_COMPONENT_AI,

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
    g_spr_brk_paddel,       // sprite ptr
    _breakout_man_game_paddel_bg,

    // anim component
    0,          // total num of frames
    0,          // index of the current frame
    0x0000,     // array of ptr to sprite ptrs

    // ai component
    breakout_man_game_behavior_userInput, // user input
};

void m_breakout_man_game_create_ball(void) {
    TEntity* entity;
    entity = cme_create();
    cpct_memcpy(entity, &m_breakout_entity_ballTemplate, sizeof(TEntity));
    entity->pmem = csr_getScreenPtr(
        CSR_PHY_TO_PX(entity->world_x),
        CSR_PHY_TO_PX(entity->world_y)
    );
    csp_addEntity(entity); // add entity to physics system
}

void m_breakout_man_game_create_paddel(void) {
    TEntity* entity = cme_create();
    cpct_memcpy(entity, &m_breakout_entity_paddelTemplate, sizeof(TEntity));
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        CSR_WORLD_TO_SCREEN_X(entity->world_x), 
        CSR_WORLD_TO_SCREEN_Y(entity->world_y)
    );
    csp_addEntity(entity); // add entity to physics system
}

void m_breakout_man_game_create_bricks(void) {
    i16 fromY = 2 * BRK_BRICK_WORLD_H;
    i16 toY = 4 * BRK_BRICK_WORLD_H;

    for (i16 y = fromY; y <= toY ; y += BRK_BRICK_WORLD_H) {
        i16 fromX = 2 * BRK_BRICK_WORLD_W;
        i16 toX   = 4 * BRK_BRICK_WORLD_W;
        for (i16 x = fromX; x <= toX ; x += BRK_BRICK_WORLD_W) {
            man_bricks_create(x, y);
        }
    }
}

void m_breakout_man_game_create_entities(void) {
    //
    // ball
    //
    // m_breakout_man_game_create_ball();

    //
    // paddel
    //
    // m_breakout_man_game_create_paddel();

    //
    // bricks
    //
    m_breakout_man_game_create_bricks();
}

void breakout_man_game_init(void) {
    TEEM_entity *e;

    ers_init(); // render system
    eps_init(); // physics system

    eem_init(); // entity manager

    man_bricks_init();
    m_breakout_man_game_create_entities();

    // TEntity *entity;

    // // init systems
    // csp_init(); // physics system
    // csr_init(); // render system
    // csa_init(); // anim system

    // // init managers
    // cme_init();         // entity manager
    // man_bricks_init();  // bricks manager

    // // create initial entities
    // m_breakout_man_game_create_entities();
    breakout_sys_render_init();
}