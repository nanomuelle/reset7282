#include <pong/man/entity/entity.h>
#include <pong/sys/physics/physics.h>
#include <pong/sys/render/render.h>
#include <pong/man/game/game.h>

#include <man/objs/objs.h>

void _createPongEntity(TPongEntityId id, i16 x, i16 y, u16 w, u16 h, i16 vx, i16 vy, void* ai) {
    TPongEntity *entity = pong_man_entity_create();
    entity->id = id;
    entity->x = x;
    entity->y = y;
    entity->w = w + 127;  // 2 bytes => 4px mode 1
    entity->h = h;
    entity->vx = vx;
    entity->vy = vy;
    entity->color = cpct_px2byteM1(3, 3, 3, 3);
    entity->render_w = HI(entity->w);
    entity->render_h = HI(entity->h);
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START,
        PONG_WORLD_TO_SCREEN_X(x),
        PONG_WORLD_TO_SCREEN_Y(y)
    );
    entity->ai = ai;
}

void pong_man_entity_init(void) {
    TPongEntity *entity;

    _pong_man_entity_numEntities = 0;
    cpct_memset(_pong_man_entity_buffer, 0, PONG_MAN_ENTITY_BUFFER_SIZE * sizeof(TPongEntity));

    // ball
    _createPongEntity(
        PONG_ENTITY_ID_BALL,
        PONG_WORLD_BALL_X,
        PONG_WORLD_BALL_Y,
        PONG_WORLD_BALL_W,
        PONG_WORLD_BALL_H,
        PONG_WORLD_BALL_VX,
        PONG_WORLD_BALL_VY,
        0 // no ai
    );

    // left player (ai)
    _createPongEntity(
        PONG_ENTITY_ID_LEFT_PADDEL,
        PONG_WORLD_LEFT_PADDEL_X,
        PONG_WORLD_LEFT_PADDEL_Y,
        PONG_WORLD_PADDEL_W,
        PONG_WORLD_PADDEL_H,
        PONG_WORLD_PADDEL_VX,
        PONG_WORLD_PADDEL_VY,
        pong_man_game_behavior_followBall
    );

    if (man_objs_isInRoom(OBJ_ID_RAQUETA, ROOM_ID_INVENTARIO)) {
        // right player (user)
        _createPongEntity(
            PONG_ENTITY_ID_RIGHT_PADDEL,
            PONG_WORLD_RIGHT_PADDEL_X,
            PONG_WORLD_RIGHT_PADDEL_Y,
            PONG_WORLD_PADDEL_W,
            PONG_WORLD_PADDEL_H,
            0,
            0,
            pong_man_game_behavior_userInput
        );
    }
}