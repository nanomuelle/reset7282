#include <breakout/sys/collisions/collisions.h>
i16 flip_vx;
i16 flip_vy;
i16 next_vx;

void m_breakout_sys_collisions_crop_ball_velocity() {
    if (m_breakout_sys_collisions_ball->ph.vx > BREAKOUT_WORLD_BALL_MAX_VX) {
        m_breakout_sys_collisions_ball->ph.vx = BREAKOUT_WORLD_BALL_MAX_VX;
    } else if (m_breakout_sys_collisions_ball->ph.vx < -BREAKOUT_WORLD_BALL_MAX_VX) {
        m_breakout_sys_collisions_ball->ph.vx = -BREAKOUT_WORLD_BALL_MAX_VX;
    }

    if (m_breakout_sys_collisions_ball->ph.vy > BREAKOUT_WORLD_BALL_MAX_VY) {
        m_breakout_sys_collisions_ball->ph.vy = BREAKOUT_WORLD_BALL_MAX_VY;
    } else if (m_breakout_sys_collisions_ball->ph.vy < -BREAKOUT_WORLD_BALL_MAX_VY) {
        m_breakout_sys_collisions_ball->ph.vy = -BREAKOUT_WORLD_BALL_MAX_VY;
    }
}

void m_breakout_sys_collisions_manage_x_axis_collision(TEEM_entity *other) {
    // collision vs left border ?
//    if (m_breakout_sys_collisions_ball->ph.vx > 0) {
        u16 other_x = other->tr.world.x;
        if (other_x >= m_breakout_sys_collisions_ball->tr.world.x && other_x <= m_breakout_sys_collisions_ball->tr.world.x2) {
            flip_vx = 1;
        } else {
//    } else { // collision vs right border ?
        u16 other_x2 = other->tr.world.x2;
        if (other_x2 >= m_breakout_sys_collisions_ball->tr.world.x && other_x2 <= m_breakout_sys_collisions_ball->tr.world.x2) {
            flip_vx = 1;
        }
    }
}

void m_breakout_sys_collisions_manage_y_axis_collision(TEEM_entity *other) {
    // collision vs bottom border ?
    u16 other_y2 = other->tr.world.y2;
    if (other_y2 >= m_breakout_sys_collisions_ball->tr.world.y &&
        other_y2 <= m_breakout_sys_collisions_ball->tr.world.y2) {
        flip_vy = 1;
    } else {
        // collision vs top border ?
        u16 other_y = other->tr.world.y;
        if (other_y >= m_breakout_sys_collisions_ball->tr.world.y &&
            other_y <= m_breakout_sys_collisions_ball->tr.world.y2) {
            flip_vy = 1;
        }
    }
}

void _breakout_sys_collisions_checkCollisionsVsBall(TEEM_entity *other) {
    if (other != m_breakout_sys_collisions_ball) {
        if (eps_check_collision(m_breakout_sys_collisions_ball, other)) {
            m_breakout_sys_collisions_manage_x_axis_collision(other);
            m_breakout_sys_collisions_manage_y_axis_collision(other);

            if (other->id == BRK_ENTITY_ID_BRICK) {
                eem_kill(other);
            } else if (other->id == BRK_ENTITY_ID_PADDEL) {
                next_vx += (other->ph.vx >> 2);
            }
        }
    }
}

u8 m_breakout_sys_collisions_discardBricksCollisions(void) {
    if (m_breakout_sys_collisions_ball->tr.world.y2 < BREAKOUT_WORLD_PADDEL_Y) {
        if ((m_breakout_sys_collisions_ball->tr.world.y > BRK_WORLD_BRICKS_Y2)  ||
            (m_breakout_sys_collisions_ball->tr.world.y2 < BRK_WORLD_BRICKS_Y1) ||
            (m_breakout_sys_collisions_ball->tr.world.x > BRK_WORLD_BRICKS_X2)  ||
            (m_breakout_sys_collisions_ball->tr.world.x2 < BRK_WORLD_BRICKS_X1)
        ) {
            return 1;
        }
    }
    return 0;
}

void breakout_sys_collisions_update(void) {
    if (m_breakout_sys_collisions_discardBricksCollisions()) {
        return;
    }

    flip_vx = 0;
    flip_vy = 0;
    next_vx = m_breakout_sys_collisions_ball->ph.vx;
    eem_for_all(_breakout_sys_collisions_checkCollisionsVsBall);
    if (flip_vx) {
        m_breakout_sys_collisions_ball->tr.world.x -= m_breakout_sys_collisions_ball->ph.vx; // restore pos
        m_breakout_sys_collisions_ball->ph.vx = -next_vx;          // flip vx
    }
    if (flip_vy) {
        m_breakout_sys_collisions_ball->tr.world.y -= m_breakout_sys_collisions_ball->ph.vy; // restore pos
        m_breakout_sys_collisions_ball->ph.vy = -m_breakout_sys_collisions_ball->ph.vy;
    }
    m_breakout_sys_collisions_crop_ball_velocity();
}