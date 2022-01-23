#include "bricks.h"
#include <breakout/sys/render/render.h>

const u8 m_man_bricks_bg_buffer[
    BRK_BRICKS_MAX * 
    G_SPR_BRK_BRICK_M1_0_W * 
    G_SPR_BRK_BRICK_M1_0_H
];
u8  m_man_bricks_num;
u8* m_man_bricks_next_bg_free;
