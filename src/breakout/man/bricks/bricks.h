#pragma once

#include <breakout/breakout.h>

// PRIVATE
#define BRK_BRICKS_MAX 50
#define BRK_BRICK_WORLD_W (EPS_PX_TO_WORLD(ERS_BYTES_TO_PX(G_SPR_BRK_BRICK_M1_0_W - 1)))
#define BRK_BRICK_WORLD_H (EPS_PX_TO_WORLD(G_SPR_BRK_BRICK_M1_0_H) )

extern const TEEM_entity m_man_bricks_brick_template;
extern const u8 m_man_bricks_bg_buffer[BRK_BRICKS_MAX * G_SPR_BRK_BRICK_M1_0_W * G_SPR_BRK_BRICK_M1_0_H];
extern u8 m_man_bricks_num;
extern u8* m_man_bricks_next_bg_free;

// PUBLIC
extern void man_bricks_init(void);
extern TEEM_entity* man_bricks_create(u16 x, u16 y);
