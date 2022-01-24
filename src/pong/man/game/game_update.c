#include <pong/man/game/game.h>
#include <pong/man/score/score.h>
#include <pong/sys/ai/ai.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/game/game.h>

#define PONG_BALL_WORLD_X (EPS_WORLD_W / 2)
#define PONG_BALL_WORLD_Y (EPS_WORLD_H / 2)

TEEM_entity* m_pong_man_game_ball;

void m_pong_man_game_bounceBall(TEEM_entity *other) {
    TEEM_entity* ball = m_pong_man_game_ball;

    i16 vy = ball->ph.vy;
    i16 vx = ball->ph.vx;

    // manage x axis => increase vx
    if (vx > 0) {
        vx += PONG_BALL_WORLD_IVX;
    } else {
        vx -= PONG_BALL_WORLD_IVX;
    }

    // crop vx
    if (vx > PONG_BALL_WORLD_MAX_VX) {
        vx = PONG_BALL_WORLD_MAX_VX;
    } else if (vx < PONG_BALL_WORLD_MIN_VX) {
        vx = PONG_BALL_WORLD_MIN_VX;
    }

    ball->ph.vx = -vx;

    // manage y axis => increase according to paddel vy
    vy += other->ph.vy >> 2;

    // crop vy
    if (vy > PONG_BALL_WORLD_MAX_VY) {
        vy = PONG_BALL_WORLD_MAX_VY;
    } else if (vy < PONG_BALL_WORLD_MIN_VY) {
        vy = PONG_BALL_WORLD_MIN_VY;
    }

    ball->ph.vy = vy;
}

void m_pong_man_game_checkScore() {
    if (m_pong_man_game_ball->tr.world.x < EPS_PX_TO_WORLD(4)) {
        pong_man_score_incRightPlayer();
        m_pong_man_game_ball->tr.world.x = EPS_WORLD_MAX_X;
        m_pong_man_game_ball->tr.world.y = EPS_WORLD_MAX_Y;
    }

    if ((m_pong_man_game_ball->tr.world.x + m_pong_man_game_ball->tr.world.w) > (EPS_WORLD_MAX_X - EPS_PX_TO_WORLD(4)) ) {
        pong_man_score_incLeftPlayer();
        m_pong_man_game_ball->tr.world.x = EPS_WORLD_MAX_X;
        m_pong_man_game_ball->tr.world.y = EPS_WORLD_MAX_Y;
    }
}

void m_pong_man_game_checkGameOver(void) {
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

void m_pong_man_game_checkCollisionsVsBall(TEEM_entity *other) {
    TEEM_entity* ball = m_pong_man_game_ball;

    if (other == ball) {
        return;
    }

    if (eps_check_collision(ball, other)) {
        ball->tr.world.x -= ball->ph.vx;
        ball->tr.world.y -= ball->ph.vy;
        ball->ph.vx = -ball->ph.vx;

        // // fix pos to avoid solapation with paddel 
        // if (ball->tr.world.x <= (PONG_WORLD_LEFT_PADDEL_X + PONG_WORLD_PADDEL_W) ) {
        //     ball->tr.world.x = (PONG_WORLD_LEFT_PADDEL_X + PONG_WORLD_PADDEL_W + EPS_PX_TO_WORLD(1) );
        // } else if ((ball->tr.world.x + ball->tr.world.w) >= PONG_WORLD_RIGHT_PADDEL_X) {
        //     ball->tr.world.x = PONG_WORLD_RIGHT_PADDEL_X - EPS_PX_TO_WORLD(1);
        // }
        // ball->tr.world.y -= ball->ph.vy;

        // m_pong_man_game_bounceBall(other);
    }
}

void m_pong_man_game_checkCollisions() {
    eem_for_all(m_pong_man_game_checkCollisionsVsBall);
}

void pong_man_game_update(void) {
    m_pong_man_game_ball = eem_get_by_id(PONG_ENTITY_ID_BALL);

    pong_sys_ai_update();
    eps_update();

    m_pong_man_game_checkCollisions();
    // // m_pong_man_game_checkScore();
    // // m_pong_man_game_checkGameOver();
}