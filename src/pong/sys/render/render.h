#ifndef PONG_SYS_RENDER
#define PONG_SYS_RENDER

#include <globals.h>

#define PONG_SYS_RENDER_BG_COLOR    0b000000
#define PONG_SYS_RENDER_FG_COLOR    0b010101

#define PONG_SYS_RENDER_PHY_TO_PX(px)  (HI(px)) // PHYSICS TO PX UNITS

#define PONG_SYS_RENDER_ENTITY_OFFSET_X    (ROOM_TXT_BOX_X + (ROOM_TXT_BOX_W >> 1))
#define PONG_SYS_RENDER_ENTITY_OFFSET_Y    (ROOM_TXT_BOX_Y + (ROOM_TXT_BOX_H >> 1))
#define WORLD_TO_SCREEN_X(x)               (PONG_SYS_RENDER_ENTITY_OFFSET_X + (PONG_SYS_RENDER_PHY_TO_PX(x)))
#define WORLD_TO_SCREEN_Y(y)               (PONG_SYS_RENDER_ENTITY_OFFSET_Y + (PONG_SYS_RENDER_PHY_TO_PX(y)))

// PUBLIC
extern void pong_sys_render_init(void);
extern void pong_sys_render_update(void);

#endif