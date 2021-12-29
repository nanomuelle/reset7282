#include <pong/man/game/game.h>
#include <pong/man/score/score.h>
#include <pong/sys/physics/physics.h>

void _checkLeftPaddelCollision(TPongEntity *ball) {
    // left paddel
    TPongEntity *paddel = pong_man_entity_getById(PONG_ENTITY_ID_LEFT_PADDEL);    
    i16 vy = ball->vy;

    if (ball->vx > 0 || 
        ball->x > (paddel->x + paddel->w) ||
        (ball->x + ball->w) < paddel->x ||
        ball->y > (paddel->y + paddel->h) ||
        (ball->y + ball->h) < paddel->y
        ) {
        return;
    }

    ball->vx = -ball->vx;
    vy += (paddel->vy / 4);
    if (vy > PONG_WORLD_BALL_MAX_VY) {
        vy = PONG_WORLD_BALL_MAX_VY;
    } else if (vy < -PONG_WORLD_BALL_MAX_VY) {
        vy = -PONG_WORLD_BALL_MAX_VY;
    }
}

void _checkScore(TPongEntity *ball) {
    if (ball->x == PONG_WORLD_MIN_X) {
        pong_man_score_incRightPlayer();
        ball->x = PONG_WORLD_BALL_X;
        ball->y = PONG_WORLD_BALL_Y;
    }

    if ((ball->x + ball->w) == PONG_WORLD_MAX_X) {
        pong_man_score_incLeftPlayer();
        ball->x = PONG_WORLD_BALL_X;
        ball->y = PONG_WORLD_BALL_Y;
    }
}

void pong_man_game_update(void) {
    TPongEntity *ball = pong_man_entity_getById(PONG_ENTITY_ID_BALL);

    pong_sys_ai_update();
    pong_sys_physics_update();

    _checkLeftPaddelCollision(ball);
    _checkScore(ball);
}