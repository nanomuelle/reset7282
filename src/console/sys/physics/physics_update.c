#include "physics.h"

void m_csp_updateOne(TEntity *entity) {
    u8 state = entity->state;
    if ((state & CME_ENTITY_STATE_DEAD) == 0) {
        i16 vx = entity->world_vx;
        i16 vy = entity->world_vy;

        if (vx == 0 && vy == 0) {
            cme_resetStateMoved(entity);
            return;
        }

        cme_setStateMoved(entity);
        {
            if (vx != 0) {
                u16 old_x = entity->world_x;
                u16 x = old_x + vx;

                // crop x to bounds
                if (vx < 0) {
                    if (x > old_x) {
                        x = CSP_WORLD_MIN_X;
                        entity->world_vx = -vx;
                    }
                } else {
                    u16 max_x = CSP_WORLD_MAX_X - entity->world_w;
                    if (x > max_x || x < old_x) {
                        x = max_x;
                        entity->world_vx = -vx;
                    }
                }
                entity->world_x = x;
            }
        }

        {
            if (vy != 0) {
                u16 old_y = entity->world_y;
                u16 y = old_y + vy;
                if (vy < 0) {
                    if (y > old_y) {
                        y = CSP_WORLD_MIN_Y;
                        entity->world_vy = -vy;
                    }
                } else {
                    u16 max_y = CSP_WORLD_MAX_Y - entity->world_h;
                    if (y > max_y || y < old_y) {
                        y = max_y;
                        entity->world_vy = -vy;
                    }
                }
                entity->world_y = y;
            }
        }
    }
}

void csp_update(void) {
    TEntity **entity = m_csp_entities;
    while(*entity != CSP_INVALID_ENTITY) {
        m_csp_updateOne(*entity);
        ++entity;
    }
}