#pragma once

#include <breakout/breakout.h>

// PRIVATE
extern TEEM_entity* m_breakout_sys_collisions_ball;

// PUBLIC
extern void breakout_sys_collisions_init(void);
extern void breakout_sys_collisions_update(void);