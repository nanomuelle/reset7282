#pragma once

#include <globals.h>
#include <console/console.h>

// CSR => CONSOLA RENDER SYS
#define CSR_PHY_TO_PX(px)  ((u16) HI(px) ) // PHYSICS TO PX UNITS

// #define CSR_ENTITY_OFFSET_X         ( ROOM_TXT_BOX_X + (ROOM_TXT_BOX_W >> 1) - 1 ) // bytes
// #define CSR_ENTITY_OFFSET_Y         ( ROOM_TXT_BOX_Y + (ROOM_TXT_BOX_H >> 1) - 2 ) // pixels

#define CSR_ENTITY_OFFSET_X         ((u16) ROOM_TXT_BOX_X * 4 ) // bytes to px
#define CSR_ENTITY_OFFSET_Y         ((u16) ROOM_TXT_BOX_Y )          // pixels

// #define CSR_WORLD_TO_SCREEN_X(x)    (CSR_ENTITY_OFFSET_X + (CSR_PHY_TO_PX(x)))
#define CSR_WORLD_TO_SCREEN_X(x)    ((u16) CSR_ENTITY_OFFSET_X + CSR_PHY_TO_PX(x) )
#define CSR_WORLD_TO_SCREEN_Y(y)    ((u16) CSR_ENTITY_OFFSET_Y + CSR_PHY_TO_PX(y) )

// PUBLIC
extern u8*  csr_getScreenPtr        (u16 x, u16 y);
extern void csr_init                (void);
extern void csr_update              (void);
extern void csr_update_one          (TEntity *);
extern void csr_capture_one_bg      (TEntity *);
extern void csr_restore_bg_one      (TEntity *);
extern void csr_draw_one            (TEntity *);
extern void csr_printChar           (u16 ascii, u8 x, u8 y, u8 pen);
extern void csr_draw_box            (TEntity *e, u8 pen);