#include "eps.h"

u8 eps_check_collision(TEEM_entity *e1, TEEM_entity *e2) {
    {
        u16 x1 = e1->tr.world.x;
        u16 x2 = e2->tr.world.x;

        if (x1 >= (x2 + e2->tr.world.w)) return 0;
        if (x2 >= (x1 + e1->tr.world.w)) return 0;
    }

    {
        u16 y1 = e1->tr.world.y;
        u16 y2 = e2->tr.world.y;

        if (y1 >= (y2 + e2->tr.world.h)) return 0;
        if (y2 >= (y1 + e1->tr.world.h)) return 0;
    }

    return 1;
}
