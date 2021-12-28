#ifndef PONG_SYS_PHYSICS
#define PONG_SYS_PHYSICS

#include <globals.h>
#include <pong/pong.h>

// PHYSICS WORLD

// (-HALF_W, -HALF_H) ... (0, -HALF_H) ... (HALF_W, -HALF_H)
//        ...              ...                   ...
// (-HALF_W,       0) ... (0, 0)       ... (HALF_W,       0)
//        ...              ...                   ...
// (-HALF_W,  HALF_H) ... (0,  HALF_H) ... (HALF_W,  HALF_H)

// PUBLIC
extern void pong_sys_physics_init(void);
extern void pong_sys_physics_update(void);

#endif