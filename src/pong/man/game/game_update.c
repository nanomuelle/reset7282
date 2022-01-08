#include <pong/man/game/game.h>
#include <pong/man/score/score.h>
#include <pong/sys/physics/physics.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/game/game.h>

u8 _checkCollision(TPongEntity *ent1, TPongEntity *ent2) {
    if (ent1->x > (ent2->x + ent2->w) ||
        (ent1->x + ent1->w) < ent2->x ||
        ent1->y > (ent2->y + ent2->h) ||
        (ent1->y + ent1->h) < ent2->y
    ) {
        return 0;
    };

    return 1;
}

void _bounceBall(TPongEntity *ball, TPongEntity *paddel) {
    i16 vy = ball->vy;
    i16 vx = ball->vx;

    if (vx < 0 && vx > PONG_WORLD_BALL_MAX_VX) {
        vx -= 5;
    } else if (vx > PONG_WORLD_BALL_MAX_VX) {
        vx += 5;
    }

    vy += (paddel->vy >> 2); // vy += paddel->vy / 4
    if (vy > PONG_WORLD_BALL_MAX_VY) {
        vy = PONG_WORLD_BALL_MAX_VY;
    } else if (vy < -PONG_WORLD_BALL_MAX_VY) {
        vy = -PONG_WORLD_BALL_MAX_VY;
    }

    ball->vx = -vx;
    ball->vy = vy;
}

void _checkLeftPaddelCollision(TPongEntity *ball) {
    // left paddel
    TPongEntity *paddel = pong_man_entity_getById(PONG_ENTITY_ID_LEFT_PADDEL);

    if (paddel == 0 || ball->vx > 0 || _checkCollision(ball, paddel) == 0) {
        return;
    }

    _bounceBall(ball, paddel);
}

void _checkRightPaddelCollision(TPongEntity *ball) {
    // right paddel
    TPongEntity *paddel = pong_man_entity_getById(PONG_ENTITY_ID_RIGHT_PADDEL);

    if (paddel == 0 || ball->vx < 0 || _checkCollision(ball, paddel) == 0) {
        return;
    }

    _bounceBall(ball, paddel);
}

void _checkScore(TPongEntity *ball) {
    if (ball->x < (PONG_WORLD_MIN_X + 128)) {
        pong_man_score_incRightPlayer();
        ball->x = PONG_WORLD_BALL_X;
        ball->y = PONG_WORLD_BALL_Y;
    }

    if ((ball->x + (i16) ball->w) > (PONG_WORLD_MAX_X - 128)) {
        pong_man_score_incLeftPlayer();
        ball->x = PONG_WORLD_BALL_X;
        ball->y = PONG_WORLD_BALL_Y;
    }
}

void _checkGameOver(void) {
    if (pong_man_score_getLeftPlayer() == PONG_POINTS_TO_WIN) {
        man_rooms_setCurrentRoom(ROOM_ID_DORMITORIO_1);
        man_history_addResponse("Has perdido al Pong!");
        return;
    }

    if (pong_man_score_getRightPlayer() == PONG_POINTS_TO_WIN) {
        man_rooms_setCurrentRoom(ROOM_ID_DORMITORIO_1);
        if (man_objs_isInRoom(OBJ_ID_DEPORTIVAS, ROOM_ID_PONG)) {
            man_objs_moveToRoom(OBJ_ID_DEPORTIVAS, ROOM_ID_INVENTARIO);
            man_history_addResponse("Premio: deportivas Nike Cortez.");
        }
        man_history_addResponse("Has ganado al Pong!");
    }
}

void pong_man_game_update(void) {
    TPongEntity *ball = pong_man_entity_getById(PONG_ENTITY_ID_BALL);

    _checkGameOver();

    pong_sys_ai_update();
    pong_sys_physics_update();

    _checkLeftPaddelCollision(ball);
    _checkRightPaddelCollision(ball);
    _checkScore(ball);
}