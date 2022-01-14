#include <breakout/sys/physics/physics.h>
#include <man/entity/entity.h>

void _breakout_sys_physics_updateOne(TEntity *entity) {
    u8 state = entity->state;
    if (ENTITY_STATE_DEAD == state & ENTITY_STATE_DEAD) {
        return;
    }

    {
        i16 vx = entity->world_vx;
        if (vx != 0) {
            i16 x = entity->world_x + vx;

            // crop x to bounds
            if (x < BREAKOUT_WORLD_MIN_X) {
                x = BREAKOUT_WORLD_MIN_X;
                entity->world_vx = -vx;
            } else {
                i16 max_x = BREAKOUT_WORLD_MAX_X - entity->world_w;
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
            if (y < BREAKOUT_WORLD_MIN_Y) {
                y = BREAKOUT_WORLD_MIN_Y;
                entity->world_vy = -vy;
            } else {
                i16 max_y = BREAKOUT_WORLD_MAX_Y - entity->world_h;
                if (y > max_y) {
                    y = max_y;
                    entity->world_vy = -vy;
                }
            }
            entity->world_y = y;
        }
    }
}

void breakout_sys_physics_update(void) {
    man_entity_forAll(_breakout_sys_physics_updateOne);
}