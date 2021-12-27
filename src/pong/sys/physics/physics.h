#ifndef PONG_SYS_PHYSICS
#define PONG_SYS_PHYSICS

#include <globals.h>
#include <sys/render/render.h>


// PHYSICS WORLD

// (-HALF_W, -HALF_H) ... (0, -HALF_H) ... (HALF_W, -HALF_H)
//        ...              ...                   ...
// (-HALF_W,       0) ... (0, 0)       ... (HALF_W,       0)
//        ...              ...                   ...
// (-HALF_W,  HALF_H) ... (0,  HALF_H) ... (HALF_W,  HALF_H)

#define PONG_SYS_PHYSICS_PX_TO_PHY(v)  (256*v) // PX TO PHYSICS UNITS

#define PONG_SYS_PHYSICS_WORLD_W    (PONG_SYS_PHYSICS_PX_TO_PHY( ROOM_TXT_BOX_W ))
#define PONG_SYS_PHYSICS_WORLD_H    (PONG_SYS_PHYSICS_PX_TO_PHY( ROOM_TXT_BOX_H ))

#define PONG_SYS_PHYSICS_MIN_X      ((-PONG_SYS_PHYSICS_WORLD_W / 2) + PONG_SYS_PHYSICS_PX_TO_PHY(1))
#define PONG_SYS_PHYSICS_MAX_X      (( PONG_SYS_PHYSICS_WORLD_W / 2) - PONG_SYS_PHYSICS_PX_TO_PHY(1))

#define PONG_SYS_PHYSICS_MIN_Y      ((-PONG_SYS_PHYSICS_WORLD_H / 2) + PONG_SYS_PHYSICS_PX_TO_PHY(2))
#define PONG_SYS_PHYSICS_MAX_Y      (( PONG_SYS_PHYSICS_WORLD_H / 2) - PONG_SYS_PHYSICS_PX_TO_PHY(2))

// PUBLIC
extern void pong_sys_physics_init(void);
extern void pong_sys_physics_update(void);

#endif