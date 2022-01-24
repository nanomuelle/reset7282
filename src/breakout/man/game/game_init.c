#include "game.h"
#include <eng/eng.h>

#include <breakout/sys/render/render.h>

#include <assets/breakout_ball_m1.h>
#include <assets/breakout_paddel_m1.h>

#include <man/objs/objs.h>
#include <breakout/man/bricks/bricks.h>

const u8 _breakout_man_game_ball_bg[G_SPR_BRK_BALL_M1_0_W * G_SPR_BRK_BALL_M1_0_H];
const u8 _breakout_man_game_paddel_bg[G_SPR_BRK_PADDEL_M1_0_W * G_SPR_BRK_PADDEL_M1_0_H];

const TEEM_entity m_breakout_entity_ballTemplate = {
    BRK_ENTITY_ID_BALL,

    EEM_STATE_DEFAULT,
    EEM_COMPONENT_PHYSICS | EEM_COMPONENT_RENDER,

    {
        .world = {
            // physics component
            BREAKOUT_WORLD_BALL_X,
            BREAKOUT_WORLD_BALL_Y,
            BREAKOUT_WORLD_BALL_W,
            BREAKOUT_WORLD_BALL_H
        }
    },

    {
        (i16) EPS_PX_TO_WORLD(2), //  BREAKOUT_WORLD_BALL_VX,
        (i16) -EPS_PX_TO_WORLD(2), // BREAKOUT_WORLD_BALL_VY,
    },

    {
        // render component
        0x0000,                 // pmem
        G_SPR_BRK_BALL_M1_0_W,  // w render
        G_SPR_BRK_BALL_M1_1_H,  // h render
        g_spr_brk_ball_m1_frames,     // sprite ptr
        _breakout_man_game_ball_bg,
    },

    // // anim component
    // 4,          // total num of frames
    // 0,          // index of the current frame
    // 0x0000,     // g_spr_brk_ball_anim,     // array of ptr to sprite ptrs

    // ai component
    { 0x0000 } // no ai
};

const TEEM_entity m_breakout_entity_paddelTemplate = {
    BRK_ENTITY_ID_PADDEL,

    EEM_STATE_DEFAULT,
    EEM_COMPONENT_PHYSICS | EEM_COMPONENT_RENDER | EEM_COMPONENT_AI,

    {
        .world = {
            // physics component
            BREAKOUT_WORLD_PADDEL_X,
            BREAKOUT_WORLD_PADDEL_Y,
            BREAKOUT_WORLD_PADDEL_W,
            BREAKOUT_WORLD_PADDEL_H,

        }
    },

    {
        (i16) 0, // vx
        (i16) 0, // vy
    },

    {
        // render component
        0x0000,                         // pmem
        G_SPR_BRK_PADDEL_M1_0_W,    // w render
        G_SPR_BRK_PADDEL_M1_0_H,    // h render
        g_spr_brk_paddel_m1_frames,       // sprite ptr
        _breakout_man_game_paddel_bg,
    },

    // // anim component
    // 0,          // total num of frames
    // 0,          // index of the current frame
    // 0x0000,     // array of ptr to sprite ptrs

    // ai component
    {
        breakout_man_game_behavior_userInput, // user input
    }
};


void m_breakout_man_game_create_entity(TEEM_entity *template) {
    TEEM_entity* e = eem_create();
    cpct_memcpy(e, template, sizeof(TEEM_entity));
    e->render.pmem = ers_get_screen_ptr(e->tr.screen.x, e->tr.screen.y);
    eps_add_entity(e); // add entity to physics system
}

void m_breakout_man_game_create_bricks(void) {
    u16 fromY = 2 * BRK_BRICK_WORLD_H;
    u16 toY = fromY + (4 * BRK_BRICK_WORLD_H);

    for (u16 y = fromY; y < toY ; y += BRK_BRICK_WORLD_H) {
        u16 fromX = 3 * BRK_BRICK_WORLD_W;
        u16 toX   = fromX + (8 * BRK_BRICK_WORLD_W);
        for (u16 x = fromX; x < toX ; x += BRK_BRICK_WORLD_W) {
            man_bricks_create(x, y);
        }
    }
}

void m_breakout_man_game_create_entities(void) {
    //
    // ball
    //
    m_breakout_man_game_create_entity(&m_breakout_entity_ballTemplate);

    //
    // paddel
    //
    m_breakout_man_game_create_entity(&m_breakout_entity_paddelTemplate);

    //
    // bricks
    //
    m_breakout_man_game_create_bricks();
}

void breakout_man_game_init(void) {
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