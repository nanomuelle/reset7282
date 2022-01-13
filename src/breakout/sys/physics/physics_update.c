#include <breakout/sys/physics/physics.h>
#include <breakout/man/entity/entity.h>

void _breakout_sys_physics_updateOne(TBreakoutEntity *entity) {
    i16 x = entity->x + entity->vx;
    i16 y = entity->y + entity->vy;

    // crop x to bounds
    if (x < BREAKOUT_WORLD_MIN_X) {
        x = BREAKOUT_WORLD_MIN_X;
        entity->vx = -entity->vx;
    } else {
        i16 max_x = BREAKOUT_WORLD_MAX_X - entity->w;
        if (x > max_x) {
            x = max_x;
            entity->vx = -entity->vx;
        }
    }

    // crop y to bounds
    if (y < BREAKOUT_WORLD_MIN_Y) {
        y = BREAKOUT_WORLD_MIN_Y;
        entity->vy = -entity->vy;
    } else {
        i16 max_y = BREAKOUT_WORLD_MAX_Y - entity->h;
        if (y > max_y) {
            y = max_y;
            entity->vy = -entity->vy;
        }
    }

    entity->x = x;
    entity->y = y;
}

void breakout_sys_physics_update(void) {
    breakout_man_entity_forEach(_breakout_sys_physics_updateOne);
}