#include <breakout/man/game/game.h>
#include <breakout/man/entity/entity.h>
#include <breakout/sys/render/render.h>

#include <assets/breakout_ball.h>
#include <assets/breakout_paddel.h>

#include <man/objs/objs.h>

void _createBreakoutEntity(TBreakoutEntityId id, i16 x, i16 y, u16 w, u16 h, i16 vx, i16 vy, u8* sprite, void* ai) {
    TBreakoutEntity *entity = breakout_man_entity_create();
    entity->id = id;
    entity->x = x;
    entity->y = y;
    entity->w = w + 127;  // 2 bytes => 4px mode 1
    entity->h = h;
    entity->vx = vx;
    entity->vy = vy;
    entity->sprite = sprite;
    entity->render_w = HI(entity->w);
    entity->render_h = HI(entity->h);
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START,
        BREAKOUT_WORLD_TO_SCREEN_X(x),
        BREAKOUT_WORLD_TO_SCREEN_Y(y)
    );
    entity->ai = ai;
}

void _init_breakout_entities(void) {
    breakout_man_entity_init();

    // ball
    _createBreakoutEntity(
        BREAKOUT_ENTITY_ID_BALL,
        BREAKOUT_WORLD_BALL_X,
        BREAKOUT_WORLD_BALL_Y,
        BREAKOUT_WORLD_BALL_W,
        BREAKOUT_WORLD_BALL_H,
        0, // BREAKOUT_WORLD_BALL_VX,
        0, // BREAKOUT_WORLD_BALL_VY,
        g_sprite_breakout_ball,
        0 // no ai
    );

//    if (man_objs_isInRoom(OBJ_ID_RAQUETA, ROOM_ID_INVENTARIO)) {
        // player (user)
        _createBreakoutEntity(
            BREAKOUT_ENTITY_ID_PADDEL,
            BREAKOUT_WORLD_PADDEL_X,
            BREAKOUT_WORLD_PADDEL_Y,
            BREAKOUT_WORLD_PADDEL_W,
            BREAKOUT_WORLD_PADDEL_H,
            0,  // initial vx
            0,  // initial vy
            g_sprite_breakout_paddel,
            breakout_man_game_behavior_userInput
        );
//     }
}

void breakout_man_game_init(void) {
    _init_breakout_entities();
    // breakout_man_score_init();

    // breakout_sys_render_init();
    // breakout_sys_input_init();
    // breakout_sys_ai_init();
    // breakout_sys_physics_init();
}