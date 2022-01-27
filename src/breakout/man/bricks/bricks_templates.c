#include "bricks.h"

const TEEM_entity m_man_bricks_brick_template = {
    BRK_ENTITY_ID_BRICK,

    EEM_STATE_DEFAULT,
    EEM_COMPONENT_RENDER,

    {
        .world = {
            0, // world x
            0, // world y
            BRK_BRICK_WORLD_W, // world w
            BRK_BRICK_WORLD_H, // world h,
            0 + BRK_BRICK_WORLD_W, // x2
            0 + BRK_BRICK_WORLD_H  // y2
        }
    },

    {
        (i16) 0, // vx
        (i16) 0  // vy
    },

    {
        // render component
        0x0000,                                     // pmem
        0,
        G_SPR_BRK_BRICK_M1_0_W,      // w render
        G_SPR_BRK_BRICK_M1_0_H,      // h render
        g_spr_brk_brick_m1_frames,   // sprite ptr
        0x0000,
    },

    // ai component
    { 0x0000 } // no ai
};
