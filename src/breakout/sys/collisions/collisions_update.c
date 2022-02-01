#include <breakout/sys/collisions/collisions.h>
i16 flip_vx;
i16 flip_vy;
i16 next_vx;

// void m_breakout_sys_collisions_crop_ball_velocity() {
//     if (ball->ph.vx > BREAKOUT_WORLD_BALL_MAX_VX) {
//         ball->ph.vx = BREAKOUT_WORLD_BALL_MAX_VX;
//     } else if (ball->ph.vx < -BREAKOUT_WORLD_BALL_MAX_VX) {
//         ball->ph.vx = -BREAKOUT_WORLD_BALL_MAX_VX;
//     }

//     if (ball->ph.vy > BREAKOUT_WORLD_BALL_MAX_VY) {
//         ball->ph.vy = BREAKOUT_WORLD_BALL_MAX_VY;
//     } else if (ball->ph.vy < -BREAKOUT_WORLD_BALL_MAX_VY) {
//         ball->ph.vy = -BREAKOUT_WORLD_BALL_MAX_VY;
//     }
// }

void m_breakout_sys_collisions_manage_x_axis_collision(TEEM_entity *ball, TEEM_entity *other) {
    // collision vs left border ?
    u16 other_x = other->tr.world.x;
    if (other_x >= ball->tr.world.x && other_x <= ball->tr.world.x2) {
        flip_vx = 1;
    } else { // collision vs right border ?
        u16 other_x2 = other->tr.world.x2;
        if (other_x2 >= ball->tr.world.x && other_x2 <= ball->tr.world.x2) {
            flip_vx = 1;
        }
    }
}

void m_breakout_sys_collisions_manage_y_axis_collision(TEEM_entity *ball, TEEM_entity *other) {
    // collision vs bottom border ?
    u16 other_y2 = other->tr.world.y2;
    if (other_y2 >= ball->tr.world.y &&
        other_y2 <= ball->tr.world.y2) {
        flip_vy = 1;
    } else {
        // collision vs top border ?
        u16 other_y = other->tr.world.y;
        if (other_y >= ball->tr.world.y &&
            other_y <= ball->tr.world.y2) {
            flip_vy = 1;
        }
    }
}

// void _breakout_sys_collisions_checkCollisionsVsBall(TEEM_entity *other) {
//     if (other != ball) {
//         if (eps_check_collision(ball, other)) {
//             m_breakout_sys_collisions_manage_x_axis_collision(other);
//             m_breakout_sys_collisions_manage_y_axis_collision(other);

//             if (other->id == BRK_ENTITY_ID_BRICK) {
//                 eem_kill(other);
//             } else if (other->id == BRK_ENTITY_ID_PADDEL) {
//                 next_vx += (other->ph.vx >> 2);
//             }
//         }
//     }
// }

u8 m_breakout_sys_collisions_discardBricksCollisions(TEEM_entity* ball) {
    if (ball->tr.world.y2 < BREAKOUT_WORLD_PADDEL_Y) {
        if ((ball->tr.world.y > BRK_WORLD_BRICKS_Y2)  ||
            (ball->tr.world.y2 < BRK_WORLD_BRICKS_Y1) ||
            (ball->tr.world.x > BRK_WORLD_BRICKS_X2)  ||
            (ball->tr.world.x2 < BRK_WORLD_BRICKS_X1)
        ) {
            return 1;
        }
    }
    return 0;
}

u8 breakout_sys_collisions_checkLimits(TEEM_entity *e) {
    u8 res = 0;

    if (e->tr.world.x < BRK_LIMIT_LEFT) {
        e->tr.world.x = BRK_LIMIT_LEFT;
        e->ph.vx = -e->ph.vx;
        return 1;
    } else if (e->tr.world.x2 > BRK_LIMIT_RIGHT) {
        e->tr.world.x = BRK_LIMIT_RIGHT - e->tr.world.w;
        e->ph.vx = -e->ph.vx;
        return 2;
    }

    if (e->tr.world.y < BRK_LIMIT_TOP) {
        e->tr.world.y = BRK_LIMIT_TOP;
        e->ph.vy = -e->ph.vy;
        return 3;
    }

    if (e->tr.world.y2 > BRK_LIMIT_BOTTOM) {
        e->tr.world.y = BRK_LIMIT_BOTTOM - e->tr.world.h;
        e->ph.vy = -e->ph.vy;
        return 4;
    }

    return 0;
}

void handle_collision(TECM_collision* c) {
    TEEM_entity* e1 = c->e1;
    TEEM_entity* e2 = c->e2;

    if (e1->id == BRK_ENTITY_ID_BALL) {
        m_breakout_sys_collisions_manage_x_axis_collision(e1, e2);
        m_breakout_sys_collisions_manage_y_axis_collision(e1, e2);
    }

    if (e2->id == BRK_ENTITY_ID_BRICK) {
        eem_set_state_dead(e2);
    }
}

void breakout_sys_collisions_update(void) {
    TEEM_entity* ball = eem_get_by_id(BRK_ENTITY_ID_BALL);
    breakout_sys_collisions_checkLimits(m_breakout_sys_collisions_paddel);

    // check playzone limits
    if (breakout_sys_collisions_checkLimits(ball)) {
        return;
    }

    // quick discard collisions vs bricks
    if (m_breakout_sys_collisions_discardBricksCollisions(ball)) {
        return;
    }

    ecs_update(); // update engine collision system
    if (m_ecm_num > 0) {
        flip_vx = 0;
        flip_vy = 0;
        next_vx = ball->ph.vx;

        ecm_forEach(handle_collision);

        if (flip_vx || flip_vy) {
            if (flip_vx) {
                ball->ph.vx = -next_vx;          // flip vx
            }
            if (flip_vy) {
                ball->ph.vy = -ball->ph.vy;
            }
        }

        // m_breakout_sys_collisions_crop_ball_velocity();
    }

}