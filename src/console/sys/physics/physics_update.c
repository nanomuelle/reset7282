#include "physics.h"

void m_csp_updateOne(TEntity *entity) {
    u8 state = entity->state;

    if (state & ENTITY_STATE_DEAD) {
        return;
    }

    {
        i16 vx = entity->world_vx;
        if (vx != 0) {
            i16 x = entity->world_x + vx;

            // crop x to bounds
            if (x < CSP_WORLD_MIN_X) {
                x = CSP_WORLD_MIN_X;
                entity->world_vx = -vx;
            } else {
                i16 max_x = CSP_WORLD_MAX_X - entity->world_w;
                if (x > max_x) {
                    x = max_x;
                    entity->world_vx = -vx;
                }
            }
            entity->world_x = x;
        }
    }

    {
        i16 vy = entity->world_vy;
        if (vy != 0) {
            i16 y = entity->world_y + vy;

            // crop y to bounds
            if (y < CSP_WORLD_MIN_Y) {
                y = CSP_WORLD_MIN_Y;
                entity->world_vy = -vy;
            } else {
                i16 max_y = CSP_WORLD_MAX_Y - entity->world_h;
                if (y > max_y) {
                    y = max_y;
                    entity->world_vy = -vy;
                }
            }
            entity->world_y = y;
        }
    }
}

void csp_update(void) {
    TEntity **entity = m_csp_entities;
    while( *entity != CSP_INVALID_ENTITY) {
        m_csp_updateOne(*entity);
        ++entity;
    }
    // man_entity_forAll(m_csp_updateOne);
}