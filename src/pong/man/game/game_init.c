#include <pong/man/game/game.h>
#include <pong/man/score/score.h>

// #include <pong/sys/render/render.h>
#include <console/sys/render/render.h>
#include <console/sys/physics/physics.h>

#include <pong/sys/input/input.h>
#include <pong/sys/ai/ai.h>

#include <man/objs/objs.h>

#include <assets/pong_paddel_m1.h>
#include <assets/pong_ball_m1.h>

const u8 m_pong_man_game_ball_bg[G_SPR_PONG_BALL_M1_0_W * G_SPR_PONG_BALL_M1_0_H];
const TEntity m_pong_man_game_ball_template = {
    PONG_ENTITY_ID_BALL,

    CME_ENTITY_STATE_DEFAULT,
    CME_ENTITY_COMPONENT_PHYSICS | CME_ENTITY_COMPONENT_RENDER,

    // Physics component
    3 * CSP_WORLD_W / 4,
    CSP_WORLD_H / 2,
    CSP_PX_TO_WORLD( M1_BYTES_TO_PX(G_SPR_PONG_BALL_M1_0_W - 1) ),
    CSP_PX_TO_WORLD( G_SPR_PONG_BALL_M1_0_H ),
    CSP_PX_TO_WORLD(3),
    CSP_PX_TO_WORLD(2),

    // render component
    0x0000,                       // pmem
    G_SPR_PONG_BALL_M1_0_W,    // w render in bytes
    G_SPR_PONG_BALL_M1_0_H,    // h render in px
    g_spr_pong_ball_m1_frames, // sprite ptrs
    m_pong_man_game_ball_bg,      // sprite bg null => use solid box to clear

    // anim component
    0,          // total num of frames
    0,          // index of the current frame
    0x0000,     // array of ptr to sprite ptrs

    // ai component
    0x0000 // no ai
};

const u8 m_pong_man_game_paddel_bg[2 * G_SPR_PONG_PADDEL_M1_0_W * G_SPR_PONG_PADDEL_M1_0_H];
const TEntity m_pong_man_game_paddel_template = {
    PONG_ENTITY_ID_LEFT_PADDEL,

    CME_ENTITY_STATE_DEFAULT,
    CME_ENTITY_COMPONENT_PHYSICS | CME_ENTITY_COMPONENT_RENDER | CME_ENTITY_COMPONENT_AI,

    // physics component
    0,
    0,
    CSP_PX_TO_WORLD(G_SPR_PONG_PADDEL_M1_0_W - 1),
    CSP_PX_TO_WORLD(G_SPR_PONG_PADDEL_M1_0_H),
    0,
    0,

    // render component
    0x0000,                      // pmem
    G_SPR_PONG_PADDEL_M1_0_W,   // render w
    G_SPR_PONG_PADDEL_M1_0_H,   // render h
    g_spr_pong_paddel_m1_frames,       // sprite ptr
    0x0000,            // sprite bg null => use solid box

    // anim component
    0,          // total num of frames
    0,          // index of the current frame
    0x0000,     // array of ptr to sprite ptrs

    // ai component
    0x0000
};

TEntity *m_pong_man_game_createEntityFromTemplate(TEntity* template) {
    TEntity *entity = cme_create();
    cpct_memcpy(entity, template, sizeof(TEntity));
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START,
        CSR_WORLD_TO_SCREEN_X(entity->world_x),
        CSR_WORLD_TO_SCREEN_Y(entity->world_y)
    );
    cme_setStateMoved(entity);
    return entity;
}

void m_pong_man_game_create_entities(void) {
    TEntity* entity;
    u8* pmem;

    // // ball
    entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_ball_template);
    entity->sprite_bg = m_pong_man_game_ball_bg;
    csp_addEntity(entity); // add ball to physics system

    // ai player
    entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_paddel_template);
    entity->world_x = PONG_WORLD_LEFT_PADDEL_X;
    entity->world_y = PONG_WORLD_LEFT_PADDEL_Y;
    entity->sprite_bg = m_pong_man_game_paddel_bg;
    entity->ai = pong_man_game_behavior_followBall;
    csp_addEntity(entity); // add ball to physics system

    // user player
// //   if (man_objs_isInRoom(OBJ_ID_RAQUETA, ROOM_ID_INVENTARIO)) {
        entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_paddel_template);
        entity->world_x = PONG_WORLD_RIGHT_PADDEL_X;
        entity->world_y = PONG_WORLD_RIGHT_PADDEL_Y;
        entity->sprite_bg = m_pong_man_game_paddel_bg + (G_SPR_PONG_PADDEL_M1_0_W * G_SPR_PONG_PADDEL_M1_0_H);
        entity->ai = pong_man_game_behavior_userInput;
        csp_addEntity(entity); // add ball to physics system
// //   }
}

void m_pong_man_game_render_bg() {
    u8 color = cpct_px2byteM1(0, PONG_PEN, PONG_PEN, 0);
    u8 *pmem = csr_getScreenPtr(
        CSR_WORLD_TO_SCREEN_X(CSP_WORLD_W / 2),
        CSR_WORLD_TO_SCREEN_Y(CSP_WORLD_MIN_Y)
    );
    cpct_drawSolidBox(pmem, color, 1, CSR_PHY_TO_PX(CSP_WORLD_H));
}

void pong_man_game_init(void) {
    // init systems
    csp_init();             // console system physics
    csr_init();             // console system render
    pong_sys_input_init();  // init input system
    pong_sys_ai_init();     // init ai system

    // init managers
    cme_init();             // init entity manager
    pong_man_score_init();  // init score manager

    // create initial entities
    m_pong_man_game_create_entities();

    // render bg
    m_pong_man_game_render_bg();

    // capture bg and first render
    cme_forAll(csr_capture_one_bg);
    cme_forAll(csr_draw_one);
}