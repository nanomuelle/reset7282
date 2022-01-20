#include "ai.h"

void pong_sys_ai_follow(TEntity *me, TEntity *target) {
    i16 y = me->world_y + (me->world_h >> 1);
    i16 target_y = target->world_vx < 0 
        ? target->world_y + (target->world_h >> 1)
        : - (me->world_h >> 1);

    i16 distance = y - target_y;

    if (distance < 0) {
        distance = -distance;
    }

    if (distance < target->world_h) {
        me->world_vy = 0;
        return;
    }

    if (y > target_y) {
        me->world_vy = -PONG_WORLD_PADDEL_VY;
    } else {
        me->world_vy = PONG_WORLD_PADDEL_VY;
    }
}
