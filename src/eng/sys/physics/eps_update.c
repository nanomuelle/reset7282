#include "eps.h"

void m_eps_update_one(TEEM_entity *e) {
    u8 state = e->state;
    if ((state & EEM_STATE_DEAD) == 0) {
        i16 vx = e->ph.vx;
        i16 vy = e->ph.vy;

        if (vx == 0 && vy == 0) {
            eem_reset_state_moved(e);
            return;
        }

        eem_set_state_moved(e);
        {
            if (vx != 0) {
                u16 old_x = e->tr.world.x;
                u16 x = old_x + vx;

                // crop x to bounds
                if (vx < 0) {
                    if (x > old_x) {
                        x = EPS_WORLD_MIN_X;
                        e->ph.vx = -vx;
                    }
                } else {
                    u16 max_x = EPS_WORLD_MAX_X - e->tr.world.w;
                    if (x > max_x || x < old_x) {
                        x = max_x;
                        e->ph.vx = -vx;
                    }
                }
                e->tr.world.x = x;
            }
        }

        {
            if (vy != 0) {
                u16 old_y = e->tr.world.y;
                u16 y = old_y + vy;
                if (vy < 0) {
                    if (y > old_y) {
                        y = EPS_WORLD_MIN_Y;
                        e->ph.vy = -vy;
                    }
                } else {
                    u16 max_y = EPS_WORLD_MAX_Y - e->tr.world.h;
                    if (y > max_y) {
                        y = max_y;
                        e->ph.vy = -vy;
                    }
                }
                e->tr.world.y = y;
            }
        }
    }
}

void eps_update(void) {
    TEEM_entity **e = m_eps_entities;
    while(*e != EPS_INVALID_ENTITY) {
        m_eps_update_one(*e);
        ++e;
    }
}