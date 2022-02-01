#pragma once

#include <eng/eng.h>

// ERS => ENGINE RENDER SYSTEM
#define ERS_BYTES_TO_PX(bytes) ( ( bytes ) * 4 )   // bytes to px mode 1
#define ERS_PX_TO_BYTES(px)    ( (px) / 4 )      // px to bytes mode 1

#define ERS_WORLD_TO_PX(px)  ( HI(px) ) // WORLD TO PX UNITS

#define ERS_SCREEN_W         ( 256 )
#define ERS_SCREEN_H         ( 160 ) // 128 )

#define ERS_OFFSET_X_BYTES   ( 8 )  // ROOM_TXT_BOX_X bytes
#define ERS_OFFSET_Y_BYTES   ( 16 ) // ROOM_TXT_BOX_Y lines

// PUBLIC
extern void ers_init                (void);
extern u8*  ers_get_screen_ptr      (u8 x, u8 y);
extern void ers_update              (void);
extern void ers_capture_one_bg      (TEEM_entity *);

extern void ers_pp_init_mask_table   (void);
extern void ers_pp_draw_sprite       (u8* pmem, u8 **sprite, u16 shift, u8 w, u8 h) __z88dk_callee;
extern void ers_restore_one_bg_exp   (u8* pmem, u8 *sprite, u8 w, u8 h, u16 shift) __z88dk_callee;
extern void ers_capture_one_bg_exp   (u8* pmem, u8 *sprite, u8 w, u8 h, u16 shift) __z88dk_callee;