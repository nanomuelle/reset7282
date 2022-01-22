#include "ai.h"

void pong_sys_ai_follow(TEntity *me, TEntity *target) {
    u16 me_half_h = me->world_h / 2;
    i16 me_center_y = me->world_y + me_half_h;
    i16 target_y = target->world_vx < 0 
        ? target->world_y + (target->world_h / 2)
        : (CSP_WORLD_H / 2) - me_half_h;

    i16 distance = me_center_y - target_y;

    if (distance < 0) {
        distance = -distance;
    }

    if (distance < target->world_h) {
        me->world_vy = 0;
        return;
    }

    if (me_center_y > target_y) {
        me->world_vy = -PONG_WORLD_PADDEL_VY;
    } else {
        me->world_vy = PONG_WORLD_PADDEL_VY;
    }
}
