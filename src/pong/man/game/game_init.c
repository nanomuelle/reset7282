#include <pong/man/game/game.h>
#include <pong/man/score/score.h>

// #include <pong/sys/render/render.h>
#include <console/sys/render/render.h>
#include <console/sys/physics/physics.h>

#include <pong/sys/input/input.h>
#include <pong/sys/ai/ai.h>

#include <man/objs/objs.h>

#include <assets/pong_ball.h>
#include <assets/pong_paddel.h>

const TEntity m_pong_man_game_ball_template = {
    PONG_ENTITY_ID_BALL,

    CME_ENTITY_STATE_DEFAULT,
    CME_ENTITY_COMPONENT_PHYSICS | CME_ENTITY_COMPONENT_RENDER,

    // Physics component
    PONG_WORLD_BALL_X,
    PONG_WORLD_BALL_Y,
    PONG_WORLD_BALL_W,
    PONG_WORLD_BALL_H,
    PONG_WORLD_BALL_VX,
    PONG_WORLD_BALL_VY,

    // render component
    0xc000,                 // pmem
    HI(PONG_WORLD_BALL_W),  // w render
    HI(PONG_WORLD_BALL_H),  // h render
    g_sprite_pong_ball,     // sprite ptr
    0x0000,                 // sprite bg null => use solid box

    // ai component
    0x0000 // no ai
};
const TEntity m_pong_man_game_paddel_template = {
    PONG_ENTITY_ID_LEFT_PADDEL,

    CME_ENTITY_STATE_DEFAULT,
    CME_ENTITY_COMPONENT_PHYSICS | CME_ENTITY_COMPONENT_RENDER | CME_ENTITY_COMPONENT_AI,

    // physics component
    0,
    0,
    PONG_WORLD_PADDEL_W,
    PONG_WORLD_PADDEL_H,
    0,
    0,

    // render component
    0xc000,                     // pmem
    HI(PONG_WORLD_PADDEL_W),    // render w
    HI(PONG_WORLD_PADDEL_H),    // render h
    g_sprite_pong_paddel,       // sprite ptr
    0x0000,                     // sprite bg null => use solid box

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

    return entity;
}

void m_pong_man_game_create_entities(void) {
    TEntity* entity;
    u8* pmem;

    // ball
    entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_ball_template);
    csp_addEntity(entity); // add ball to physics system

    // ai player
    entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_paddel_template);
    entity->world_x = PONG_WORLD_LEFT_PADDEL_X;
    entity->world_y = PONG_WORLD_LEFT_PADDEL_Y;
    entity->ai = pong_man_game_behavior_followBall;
    csp_addEntity(entity); // add ball to physics system

    // user player
    if (man_objs_isInRoom(OBJ_ID_RAQUETA, ROOM_ID_INVENTARIO)) {
        entity = m_pong_man_game_createEntityFromTemplate(&m_pong_man_game_paddel_template);
        entity->world_x = PONG_WORLD_RIGHT_PADDEL_X;
        entity->world_y = PONG_WORLD_RIGHT_PADDEL_Y;
        entity->ai = pong_man_game_behavior_userInput;
        csp_addEntity(entity); // add ball to physics system
    }
}

void pong_man_game_init(void) {
    // init systems
    csp_init();             // console system physics
    csr_init();             // console system render
    pong_sys_input_init();  // init input system
    pong_sys_ai_init();     // init ai system

    // init managers
    cme_init();      // init entity manager
    pong_man_score_init();  // init score manager

    // create initial entities
    m_pong_man_game_create_entities();
}