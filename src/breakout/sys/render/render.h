#ifndef BREAKOUT_SYS_RENDER
#define BREAKOUT_SYS_RENDER

#include <globals.h>

#define BREAKOUT_SYS_RENDER_BG_COLOR    0b000000
#define BREAKOUT_SYS_RENDER_FG_COLOR    0b010101

#define BREAKOUT_SYS_RENDER_PHY_TO_PX(px)  (HI(px)) // PHYSICS TO PX UNITS

#define BREAKOUT_SYS_RENDER_ENTITY_OFFSET_X    (ROOM_TXT_BOX_X + (ROOM_TXT_BOX_W >> 1) - 1) // bytes
#define BREAKOUT_SYS_RENDER_ENTITY_OFFSET_Y    (ROOM_TXT_BOX_Y + (ROOM_TXT_BOX_H >> 1) - 2) // pixels
#define BREAKOUT_WORLD_TO_SCREEN_X(x)          (BREAKOUT_SYS_RENDER_ENTITY_OFFSET_X + (BREAKOUT_SYS_RENDER_PHY_TO_PX(x)))
#define BREAKOUT_WORLD_TO_SCREEN_Y(y)          (BREAKOUT_SYS_RENDER_ENTITY_OFFSET_Y + (BREAKOUT_SYS_RENDER_PHY_TO_PX(y)))

// PUBLIC
extern void breakout_sys_render_init(void);
extern void breakout_sys_render_update(void);

#endif