#include <console/sys/physics/physics.h>

#include <pong/man/game/game.h>
#include <pong/man/score/score.h>
#include <pong/sys/ai/ai.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/game/game.h>

TEntity *m_pong_man_game_ball;

void m_pong_man_game_bounceBall(TEntity *other) {
    i16 vy = m_pong_man_game_ball->world_vy;
    i16 vx = m_pong_man_game_ball->world_vx;

    // restore pos to one before collision to avoid solapation
    m_pong_man_game_ball->world_x -= vx;
    m_pong_man_game_ball->world_y -= vy;

    // manage x axis => increase vx
    if (vx > 0) {
        vx += PONG_WORLD_BALL_IVX;
    } else {
        vx -= PONG_WORLD_BALL_IVX;
    }

    // crop vx
    if (vx > PONG_WORLD_BALL_MAX_VX) {
        vx = PONG_WORLD_BALL_MAX_VX;
    } else if (vx < PONG_WORLD_BALL_MIN_VX) {
        vx = PONG_WORLD_BALL_MIN_VX;
    }

    m_pong_man_game_ball->world_vx = -vx;

    // manage y axis => increase according to paddel vy
    vy += other->world_vy >> 2;

    // crop vy
    if (vy > PONG_WORLD_BALL_MAX_VY) {
        vy = PONG_WORLD_BALL_MAX_VY;
    } else if (vy < PONG_WORLD_BALL_MIN_VY) {
        vy = PONG_WORLD_BALL_MIN_VY;
    }

    m_pong_man_game_ball->world_vy = vy;
}

void m_pong_man_game_checkScore() {
    if (m_pong_man_game_ball->world_x < (CSP_WORLD_MIN_X + 128)) {
        pong_man_score_incRightPlayer();
        m_pong_man_game_ball->world_x = PONG_WORLD_BALL_X;
        m_pong_man_game_ball->world_y = PONG_WORLD_BALL_Y;
    }

    if ((m_pong_man_game_ball->world_x + m_pong_man_game_ball->world_w) > (CSP_WORLD_MAX_X - 128)) {
        pong_man_score_incLeftPlayer();
        m_pong_man_game_ball->world_x = PONG_WORLD_BALL_X;
        m_pong_man_game_ball->world_y = PONG_WORLD_BALL_Y;
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

void m_pong_man_game_checkCollisionsVsBall(TEntity *other) {
    if (other == m_pong_man_game_ball) {
        return;
    }

    if (csp_checkCollision(m_pong_man_game_ball, other)) {
        m_pong_man_game_bounceBall(other);
    }
}

void m_pong_man_game_checkCollisions() {
    cme_forAll(m_pong_man_game_checkCollisionsVsBall);
}

void pong_man_game_update(void) {
    m_pong_man_game_ball = cme_getById(PONG_ENTITY_ID_BALL);

    pong_sys_ai_update();
    csp_update();

    m_pong_man_game_checkCollisions();
    m_pong_man_game_checkScore();

    m_pong_man_game_checkGameOver();
}