#include <breakout/man/game/game.h>
#include <breakout/sys/ai/ai.h>

//
// TODO: no modificar directamente la v de la ball
//       solo marcar que hay que hacer un split en vx o vy
//       y al final de la comprobación de colisiones hacer el flip
//       Porque si se hace durante, la v que se comprueba de una 
//       a entidad a otra es diferente provocando rebotes extraños
//

i16 flip_vx;
i16 flip_vy;
i16 next_vx;

void m_breakout_man_game_crop_ball_velocity() {
    if (m_breakout_man_game_ball->ph.vx > BREAKOUT_WORLD_BALL_MAX_VX) {
        m_breakout_man_game_ball->ph.vx = BREAKOUT_WORLD_BALL_MAX_VX;
    } else if (m_breakout_man_game_ball->ph.vx < BREAKOUT_WORLD_BALL_MIN_VX) {
        m_breakout_man_game_ball->ph.vx = BREAKOUT_WORLD_BALL_MIN_VX;
    }

    if (m_breakout_man_game_ball->ph.vy > BREAKOUT_WORLD_BALL_MAX_VY) {
        m_breakout_man_game_ball->ph.vy = BREAKOUT_WORLD_BALL_MAX_VY;
    } else if (m_breakout_man_game_ball->ph.vy < BREAKOUT_WORLD_BALL_MIN_VY) {
        m_breakout_man_game_ball->ph.vy = BREAKOUT_WORLD_BALL_MIN_VY;
    }
}

void m_breakout_man_game_manage_x_axis_collision(TEEM_entity *other) {
    u16 x1 = m_breakout_man_game_ball->tr.world.x;

    // collision vs left border ?
    if (m_breakout_man_game_ball->ph.vx > 0) {
        u16 x2 = other->tr.world.x;
        u16 right1 = x1 + m_breakout_man_game_ball->tr.world.w;
        if (x2 >= x1 && x2 <= right1) {
            flip_vx = 1;
        }
    } else { // collision vs right border ?
        u16 right1 = x1 + m_breakout_man_game_ball->tr.world.w;
        u16 right2 = other->tr.world.x + other->tr.world.w;
        if (right2 >= x1 && right2 <= right1) {
            flip_vx = 1;
        }
    }
}

void m_breakout_man_game_manage_y_axis_collision(TEEM_entity *other) {
    u16 y2 = other->tr.world.y;

    // collision vs bottom border ?
    if (m_breakout_man_game_ball->ph.vy < 0) {
        u16 bottom2 = y2 + other->tr.world.h;
        if (y2 < m_breakout_man_game_ball->tr.world.y) {
            flip_vy = 1;
        }
    } else {
        u16 bottom1 = m_breakout_man_game_ball->tr.world.y + m_breakout_man_game_ball->tr.world.h;
        if (bottom1 >= y2) {
            flip_vy = 1;
        }
    }
}

void _breakout_man_game_checkCollisionsVsBall(TEEM_entity *other) {
    if (other != m_breakout_man_game_ball) {
        if (eps_check_collision(m_breakout_man_game_ball, other)) {
            m_breakout_man_game_manage_x_axis_collision(other);
            m_breakout_man_game_manage_y_axis_collision(other);

            if (other->id == BRK_ENTITY_ID_BRICK) {
                eem_kill(other);
            } else if (other->id == BRK_ENTITY_ID_PADDEL) {
                next_vx += (other->ph.vx >> 2);
            }
        }
    }
}

void _breakout_man_game_checkCollisions(void) {
    // ball = eem_get_by_id(BRK_ENTITY_ID_BALL);
    flip_vx = 0;
    flip_vy = 0;
    next_vx = m_breakout_man_game_ball->ph.vx;
    eem_for_all(_breakout_man_game_checkCollisionsVsBall);
    if (flip_vx) {
        m_breakout_man_game_ball->tr.world.x -= m_breakout_man_game_ball->ph.vx; // restore pos
        m_breakout_man_game_ball->ph.vx = -next_vx;          // flip vx
    }
    if (flip_vy) {
        m_breakout_man_game_ball->tr.world.y -= m_breakout_man_game_ball->ph.vy; // restore pos
        m_breakout_man_game_ball->ph.vy = -m_breakout_man_game_ball->ph.vy;
    }
    m_breakout_man_game_crop_ball_velocity();
}

void breakout_man_game_update(void) {
    breakout_sys_ai_update();   // ai system
    eps_update();               // physics system
    _breakout_man_game_checkCollisions(); // collisions
}