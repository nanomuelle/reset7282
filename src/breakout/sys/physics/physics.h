#ifndef BREAKOUT_SYS_PHYSICS
#define BREAKOUT_SYS_PHYSICS

#include <globals.h>
#include <breakout/breakout.h>

// PHYSICS WORLD

// (-HALF_W, -HALF_H) ... (0, -HALF_H) ... (HALF_W, -HALF_H)
//        ...              ...                   ...
// (-HALF_W,       0) ... (0, 0)       ... (HALF_W,       0)
//        ...              ...                   ...
// (-HALF_W,  HALF_H) ... (0,  HALF_H) ... (HALF_W,  HALF_H)

// PUBLIC
extern void breakout_sys_physics_init(void);
extern void breakout_sys_physics_update(void);

#endif