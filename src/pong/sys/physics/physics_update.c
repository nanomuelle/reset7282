#include <pong/sys/physics/physics.h>
#include <pong/man/entity/entity.h>



void _pong_sys_physics_updateOne(TPongEntity *entity) {
    i16 x = entity->x + entity->vx;
    i16 y = entity->y + entity->vy;

    // crop x to bounds
    if (x < PONG_WORLD_MIN_X) {
        x = PONG_WORLD_MIN_X;
        entity->vx = -entity->vx;
    } else {
        i16 max_x = PONG_WORLD_MAX_X - entity->w;
        if (x > max_x) {
            x = max_x;
            entity->vx = -entity->vx;
        }
    }

    // crop y to bounds
    if (y < PONG_WORLD_MIN_Y) {
        y = PONG_WORLD_MIN_Y;
        entity->vy = -entity->vy;
    } else {
        i16 max_y = PONG_WORLD_MAX_Y - entity->h;
        if (y > max_y) {
            y = max_y;
            entity->vy = -entity->vy;
        }
    }

    entity->x = x;
    entity->y = y;
}

void pong_sys_physics_update(void) {
    pong_man_entity_forEach(_pong_sys_physics_updateOne);
}