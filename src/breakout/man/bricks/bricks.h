#pragma once

#include <breakout/breakout.h>
#include <man/entity/entity.h>

// PRIVATE
#define MAX_BRICKS 50

extern const u8 m_man_bricks_bg_buffer[MAX_BRICKS * G_SPRITE_BREAKOUT_MEDIUM_BRICK_W * G_SPRITE_BREAKOUT_MEDIUM_BRICK_H];
extern u8 m_man_bricks_num;
extern u8* m_man_bricks_next_bg_free;

// PUBLIC
extern void man_bricks_init(void);
extern TEntity* man_bricks_create(i16 x, i16 y);
