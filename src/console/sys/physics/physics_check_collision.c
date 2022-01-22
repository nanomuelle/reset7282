#include "physics.h"

u8 csp_checkCollision(TEntity *ent1, TEntity *ent2) {
    {
        u16 x1 = ent1->world_x;
        u16 x2 = ent2->world_x;

        if (x1 >= (x2 + ent2->world_w)) return 0;
        if (x2 >= (x1 + ent1->world_w)) return 0;
    }

    {
        u16 y1 = ent1->world_y;
        u16 y2 = ent2->world_y;

        if (y1 >= (y2 + ent2->world_h)) return 0;
        if (y2 >= (y1 + ent1->world_h)) return 0;
    }

    return 1;
}
