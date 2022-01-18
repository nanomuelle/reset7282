#include <breakout/man/game/game.h>
#include <breakout/sys/ai/ai.h>
#include <breakout/sys/physics/physics.h>
#include <man/entity/entity.h>

TEntity *ball;

void m_breakout_man_game_crop_ball_velocity() {
    if (ball->world_vx > BREAKOUT_WORLD_BALL_MAX_VX) {
        ball->world_vx = BREAKOUT_WORLD_BALL_MAX_VX;
    } else if (ball->world_vx < BREAKOUT_WORLD_BALL_MIN_VX) {
        ball->world_vx = BREAKOUT_WORLD_BALL_MIN_VX;
    }

    if (ball->world_vy > BREAKOUT_WORLD_BALL_MAX_VY) {
        ball->world_vy = BREAKOUT_WORLD_BALL_MAX_VY;
    } else if (ball->world_vy < BREAKOUT_WORLD_BALL_MIN_VY) {
        ball->world_vy = BREAKOUT_WORLD_BALL_MIN_VY;
    }
}

void m_breakout_man_game_manage_x_axis_collision(TEntity *other) {
    i16 x1 = ball->world_x;
    i16 vx = ball->world_vx;
    i16 x2 = other->world_x;

    // collision vs left border ?
    if (vx > 0) {
        i16 right1 = x1 + ball->world_w;
        u8 is_collision_vs_left_border = x1 < x2 && right1 >= x2;

        if (is_collision_vs_left_border) {         // reverse vx
            vx = -vx;
        }
    }

    // collision vs right border ?
    else if (vx < 0) {
        i16 right2 = x2 + other->world_w;
        u8 is_collision_vs_right_border = x2 < x1 && right2 <= x1;
        if (is_collision_vs_right_border) {
            vx = -vx;
        }
    }

    ball->world_x -= ball->world_vx;    // restore x pos
    ball->world_vx = vx;                // set new vx
}

void m_breakout_man_game_manage_y_axis_collision(TEntity *other) {
    i16 y1 = ball->world_y;
    i16 vy = ball->world_vy;
    i16 y2 = other->world_y;

    // collision vs bottom border ?
    if (vy < 0) {
        i16 bottom2 = y2 + other->world_h;
        u8 is_collision_vs_bottom_border = y2 < y1;
        if (is_collision_vs_bottom_border) {
            vy = -vy;
        }
    }

    // collision vs top border ?
    else if (vy > 0) {
        i16 bottom1 = y1 + ball->world_h;
        u8 is_collision_vs_top_border = bottom1 >= y2;
        if (is_collision_vs_top_border) {
            vy = -vy;
        }
    }

    y1 -= ball->world_vy;
    ball->world_y  = y1;    // restore y pos
    ball->world_vy = vy;    // set new vy
}

void _breakout_man_game_checkCollisionsVsBall(TEntity *other) {
    if (other != ball) {
        if (breakout_sys_physics_checkCollision(ball, other)) {
            m_breakout_man_game_manage_x_axis_collision(other);
            m_breakout_man_game_manage_y_axis_collision(other);

            if (other->id == BREAKOUT_ENTITY_ID_BRICK) {
                man_entity_set4destroy(other);
            } else if (other->id == BREAKOUT_ENTITY_ID_PADDEL) {
                other->world_x = other->world_x - other->world_vx;
                other->world_y = other->world_y - other->world_vy;
                ball->world_vx += (other->world_vx >> 2);
                m_breakout_man_game_crop_ball_velocity();
            }
        }
    }
}

void _breakout_man_game_checkCollisions(void) {
    ball = man_entity_getById(BREAKOUT_ENTITY_ID_BALL);
    man_entity_forAll(_breakout_man_game_checkCollisionsVsBall);
}

void breakout_man_game_update(void) {
    breakout_sys_ai_update();
    breakout_sys_physics_update();
    _breakout_man_game_checkCollisions();
}