#include "ai.h"

void pong_sys_ai_follow(TEEM_entity *me, TEEM_entity *target) {
    u16 me_half_h = me->tr.world.h / 2;
    i16 me_center_y = me->tr.world.y + me_half_h;
    i16 target_y = target->ph.vx < 0 
        ? target->tr.world.y + (target->tr.world.h / 2)
        : (EPS_WORLD_MAX_Y / 2) - me_half_h;

    i16 distance = me_center_y - target_y;

    if (distance < 0) {
        distance = -distance;
    }

    if (distance < target->tr.world.h) {
        me->ph.vy = 0;
        return;
    }

    if (me_center_y > target_y) {
        me->ph.vy = -PONG_WORLD_PADDEL_VY;
    } else {
        me->ph.vy = PONG_WORLD_PADDEL_VY;
    }
}
