#pragma once

#include <globals.h>
#include <console/console.h>

// CSR => CONSOLA RENDER SYS
#define CSR_PHY_TO_PX(px)  ((u16) HI(px) ) // PHYSICS TO PX UNITS

#define CSR_SCREEN_W         ( M1_BYTES_TO_PX(ROOM_TXT_BOX_W) )
#define CSR_SCREEN_H         ( ROOM_TXT_BOX_H )
#define CSR_OFFSET_X_BYTES   ( ROOM_TXT_BOX_X ) // bytes
#define CSR_OFFSET_Y         ( ROOM_TXT_BOX_Y ) // pixels

// #define CSR_WORLD_TO_SCREEN_X(x)    (CSR_OFFSET_X + (CSR_PHY_TO_PX(x)))
#define CSR_WORLD_TO_SCREEN_X(x)    ((u16) CSR_OFFSET_X_BYTES + CSR_PHY_TO_PX(x) )
#define CSR_WORLD_TO_SCREEN_Y(y)    ((u16) CSR_OFFSET_Y + CSR_PHY_TO_PX(y) )

// PUBLIC
extern u8*  csr_getScreenPtr        (u8 x, u8 y);
extern void csr_init                (void);
extern void csr_update              (void);
extern void csr_update_one          (TEntity *);
extern void csr_capture_one_bg      (TEntity *);
extern void csr_restore_bg_one      (TEntity *);
extern void csr_draw_one            (TEntity *);
extern void csr_printChar           (u16 ascii, u8 x, u8 y, u8 pen);
extern void csr_draw_box            (TEntity *e, u8 pen);

extern void csr_init_mask_table     (void);
extern void csr_pp_drawSprite       (u8* pmem, u8 *sprite, u16 shift, u8 w, u8 h) __z88dk_callee;