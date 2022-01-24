#include <breakout/man/game/game.h>
#include <breakout/sys/ai/ai.h>

//
// TODO: no modificar directamente la v de la ball
//       solo marcar que hay que hacer un split en vx o vy
//       y al final de la comprobación de colisiones hacer el flip
//       Porque si se hace durante, la v que se comprueba de una 
//       a entidad a otra es diferente provocando rebotes extraños
//

TEEM_entity *ball;
i16 flip_vx;
i16 flip_vy;
i16 next_vx;

void m_breakout_man_game_crop_ball_velocity() {
    if (ball->ph.vx > BREAKOUT_WORLD_BALL_MAX_VX) {
        ball->ph.vx = BREAKOUT_WORLD_BALL_MAX_VX;
    } else if (ball->ph.vx < BREAKOUT_WORLD_BALL_MIN_VX) {
        ball->ph.vx = BREAKOUT_WORLD_BALL_MIN_VX;
    }

    if (ball->ph.vy > BREAKOUT_WORLD_BALL_MAX_VY) {
        ball->ph.vy = BREAKOUT_WORLD_BALL_MAX_VY;
    } else if (ball->ph.vy < BREAKOUT_WORLD_BALL_MIN_VY) {
        ball->ph.vy = BREAKOUT_WORLD_BALL_MIN_VY;
    }
}

void m_breakout_man_game_manage_x_axis_collision(TEEM_entity *other) {
    i16 x1 = ball->tr.world.x;
    i16 vx = ball->ph.vx;
    i16 x2 = other->tr.world.x;

    // collision vs left border ?
    if (vx > 0) {
        i16 right1 = x1 + ball->tr.world.w;
        u8 is_collision_vs_left_border = x1 < x2 && right1 >= x2;

        if (is_collision_vs_left_border) {         // reverse vx
            // vx = -vx;
            flip_vx = 1;
        }
    }

    // collision vs right border ?
    else if (vx < 0) {
        i16 right2 = x2 + other->tr.world.w;
        u8 is_collision_vs_right_border = x2 < x1 && right2 <= x1;
        if (is_collision_vs_right_border) {
            flip_vx = 1;
            // vx = -vx;
        }
    }

    // ball->tr.world.x -= ball->ph.vx;    // restore x pos
    // ball->ph.vx = vx;                // set new vx
}

void m_breakout_man_game_manage_y_axis_collision(TEEM_entity *other) {
    i16 y1 = ball->tr.world.y;
    i16 vy = ball->ph.vy;
    i16 y2 = other->tr.world.y;

    // collision vs bottom border ?
    if (vy < 0) {
        i16 bottom2 = y2 + other->tr.world.h;
        u8 is_collision_vs_bottom_border = y2 < y1;
        if (is_collision_vs_bottom_border) {
            // vy = -vy;
            flip_vy = 1;
        }
    }

    // collision vs top border ?
    else if (vy > 0) {
        i16 bottom1 = y1 + ball->tr.world.h;
        u8 is_collision_vs_top_border = bottom1 >= y2;
        if (is_collision_vs_top_border) {
            // vy = -vy;
            flip_vy = 1;
        }
    }

    // y1 -= ball->ph.vy;
    // ball->tr.world.y  = y1;    // restore y pos
    // ball->ph.vy = vy;    // set new vy
}

void _breakout_man_game_checkCollisionsVsBall(TEEM_entity *other) {
    if (other != ball) {
        if (eps_check_collision(ball, other)) {
            m_breakout_man_game_manage_x_axis_collision(other);
            m_breakout_man_game_manage_y_axis_collision(other);

            if (other->id == BRK_ENTITY_ID_BRICK) {
                eem_kill(other);
            } else if (other->id == BRK_ENTITY_ID_PADDEL) {
                // other->tr.world.x = other->tr.world.x - other->ph.vx;
                // other->tr.world.y = other->tr.world.y - other->ph.vy;
                next_vx += (other->ph.vx >> 2);
            }
        }
    }
}

void _breakout_man_game_checkCollisions(void) {
    ball = eem_get_by_id(BRK_ENTITY_ID_BALL);
    flip_vx = 0;
    flip_vy = 0;
    next_vx = ball->ph.vx;
    eem_for_all(_breakout_man_game_checkCollisionsVsBall);
    if (flip_vx) {
        ball->tr.world.x -= ball->ph.vx; // restore pos
        ball->ph.vx = -next_vx;          // flip vx
    }
    if (flip_vy) {
        ball->tr.world.y -= ball->ph.vy; // restore pos
        ball->ph.vy = -ball->ph.vy;
    }
    m_breakout_man_game_crop_ball_velocity();
}

void breakout_man_game_update(void) {
    breakout_sys_ai_update();   // ai system
    eps_update();               // physics system
    _breakout_man_game_checkCollisions(); // collisions
}