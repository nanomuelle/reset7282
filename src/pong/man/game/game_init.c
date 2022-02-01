#include <pong/man/game/game.h>
#include <pong/man/score/score.h>

#include <pong/sys/input/input.h>
#include <pong/sys/ai/ai.h>

#include <man/objs/objs.h>

#include <assets/pong_paddel_m1.h>
#include <assets/pong_ball_m1.h>

const u8 m_pong_man_game_ball_bg[G_SPR_PONG_BALL_M1_0_W * G_SPR_PONG_BALL_M1_0_H];
const TEEM_entity m_pong_man_game_ball_template = {
    PONG_ENTITY_ID_BALL,

    EEM_STATE_DEFAULT,
    EEM_COMPONENT_PHYSICS | EEM_COMPONENT_RENDER,
    {
        .world = {
            EPS_WORLD_MAX_X / 2,
            EPS_WORLD_MAX_Y / 2,
            EPS_PX_TO_WORLD( ERS_BYTES_TO_PX(G_SPR_PONG_BALL_M1_0_W - 1) ),
            EPS_PX_TO_WORLD( G_SPR_PONG_BALL_M1_0_H )
        }
    },
    {
        // Physics component
        EPS_PX_TO_WORLD(1),
        EPS_PX_TO_WORLD(1) / 2,
    },
    {
        // render component
        0x0000,                       // pmem
        0,                         // shift
        G_SPR_PONG_BALL_M1_0_W,    // w render in bytes
        G_SPR_PONG_BALL_M1_0_H,    // h render in px
        g_spr_pong_ball_m1_frames, // sprite ptrs
        m_pong_man_game_ball_bg,      // sprite bg null => use solid box to clear
    },

    // // anim component
    // 0,          // total num of frames
    // 0,          // index of the current frame
    // 0x0000,     // array of ptr to sprite ptrs

    // ai component
    { 0x0000 }// no ai
};

const u8 m_pong_man_game_paddel_bg[2 * G_SPR_PONG_PADDEL_M1_0_W * G_SPR_PONG_PADDEL_M1_0_H];
const TEEM_entity m_pong_man_game_paddel_template = {
    PONG_ENTITY_ID_LEFT_PADDEL,

    EEM_STATE_DEFAULT,
    EEM_COMPONENT_PHYSICS | EEM_COMPONENT_RENDER | EEM_COMPONENT_AI,

    // physics component
    {
        .world = {
            0,
            0,
            EPS_PX_TO_WORLD(G_SPR_PONG_PADDEL_M1_0_W - 1),
            EPS_PX_TO_WORLD(G_SPR_PONG_PADDEL_M1_0_H),
        }
    },

    {
        0, // vx
        0, // vy
    },

    {
        // render component
        0x0000,                      // pmem
        0,                          // shift
        G_SPR_PONG_PADDEL_M1_0_W,   // render w
        G_SPR_PONG_PADDEL_M1_0_H,   // render h
        g_spr_pong_paddel_m1_frames,       // sprite ptr
        0x0000,            // sprite bg null => use solid box
    },

    // // anim component
    // 0,          // total num of frames
    // 0,          // index of the current frame
    // 0x0000,     // array of ptr to sprite ptrs

    // ai component
    { 0x0000 }
};

TEEM_entity *m_pong_man_game_createEntityFromTemplate(TEEM_entity* template) {
    TEEM_entity *entity = eem_create();
    cpct_memcpy(entity, template, sizeof(TEEM_entity));

    // entity->render.pmem = ers_get_screen_ptr(
    //     entity->tr.screen.x,
    //     entity->tr.screen.y
    // );

    // eem_setStateMoved(entity);
    return entity;
}

void m_pong_man_game_create_entities(void) {
    TEEM_entity* entity;

    // ai player
    entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_paddel_template);
    entity->tr.world.x = PONG_WORLD_LEFT_PADDEL_X;
    entity->tr.world.y = PONG_WORLD_LEFT_PADDEL_Y;
    entity->render.sprite_bg = m_pong_man_game_paddel_bg;
    entity->ai = pong_man_game_behavior_followBall;
    eps_add_entity(entity); // add ball to physics system

    // user player
// //   if (man_objs_isInRoom(OBJ_ID_RAQUETA, ROOM_ID_INVENTARIO)) {
        entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_paddel_template);
        entity->tr.world.x = PONG_WORLD_RIGHT_PADDEL_X;
        entity->tr.world.y = PONG_WORLD_RIGHT_PADDEL_Y;
        entity->render.sprite_bg = m_pong_man_game_paddel_bg + (G_SPR_PONG_PADDEL_M1_0_W * G_SPR_PONG_PADDEL_M1_0_H);
        entity->ai = pong_man_game_behavior_userInput;
        eps_add_entity(entity); // add ball to physics system
// //   }

    // // ball
    entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_ball_template);
    entity->render.sprite_bg = m_pong_man_game_ball_bg;
    eps_add_entity(entity); // add ball to physics system

}

void m_pong_man_game_render_bg() {
    u8 color = cpct_px2byteM1(0, PONG_PEN, PONG_PEN, 0);
    u8 *pmem = ers_get_screen_ptr(ERS_SCREEN_W / 2, 0);
    cpct_drawSolidBox(pmem, color, 1, ERS_SCREEN_H);
}

void pong_man_game_init(void) {
    // // init systems
    ers_init();             // engine system render
    eps_init();             // engine system physics
    pong_sys_input_init();  // init input system
    pong_sys_ai_init();     // init ai system

    // // init managers
    eem_init();             // init entity manager
    pong_man_score_init();  // init score manager

    // // create initial entities
    m_pong_man_game_create_entities();

    // // render bg
    m_pong_man_game_render_bg();

    // // capture bg and first render
    eem_for_all(ers_capture_one_bg);
}