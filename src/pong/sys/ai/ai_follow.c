#include <pong/sys/ai/ai.h>

void pong_sys_ai_follow(TPongEntity *me, TPongEntity *target) {
    i16 y = me->y + (me->w / 2);
    i16 target_y = target->vx < 0 
        ? target->y + (target->w / 2)
        : - (me->h / 2);

    i16 distance = y - target_y;

    if (distance < 0) {
        distance = -distance;
    }

    if (distance < target->h) {
        me->vy = 0;
        return;
    }

    if (y > target_y) {
        me->vy = -PONG_WORLD_PADDEL_VY;
    } else {
        me->vy = PONG_WORLD_PADDEL_VY;
    }
}
