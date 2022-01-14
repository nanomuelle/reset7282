#include <breakout/sys/physics/physics.h>

u8 breakout_sys_physics_checkCollision(TEntity *ent1, TEntity *ent2) {
    {
        i16 x1 = ent1->world_x;
        i16 w1 = ent1->world_w;
        i16 x2 = ent2->world_x;
        i16 w2 = ent2->world_w;

        if (x1 > (x2 + w2)) return 0;
        if ((x1 + w1) < x2) return 0;
    }

    {
        i16 y1 = ent1->world_y;
        i16 h1 = ent1->world_h;
        i16 y2 = ent2->world_y;
        i16 h2 = ent2->world_h;

        if (y1 > (y2 + h2)) return 0;
        if ((y1 + h1) < y2) return 0;
    }

    return 1;
}
