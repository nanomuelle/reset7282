#include <pong/sys/ai/ai.h>

void pong_sys_ai_follow(TPongEntity *me, TPongEntity *target) {
    i16 y = me->y + (me->h >> 1);
    i16 target_y = target->vx < 0 
        ? target->y + (target->h >> 1)
        : - (me->h >> 1);

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
