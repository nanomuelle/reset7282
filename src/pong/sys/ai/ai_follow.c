#include <stdlib.h>
#include <pong/sys/ai/ai.h>

void pong_sys_ai_follow(TPongEntity *me, TPongEntity *target) {
    i16 y = me->y + (me->w / 2);
    i16 target_y = target->y + (target->w / 2);

    if (abs(y - target_y) < me->h) {
        return;
    }

    if ((y > target_y && me->vy > 0) ||
        (y < target_y && me->vy < 0) ) {
        me->vy = -me->vy;
    }
}
