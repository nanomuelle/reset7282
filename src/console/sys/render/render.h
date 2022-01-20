#pragma once

#include <globals.h>
#include <console/man/entity/entity.h>

// #define CONSOLA_SYS_RENDER_BG_COLOR    0b000000
// #define CONSOLA_SYS_RENDER_FG_COLOR    0b010101

// CSR => CONSOLA RENDER SYS
#define CSR_PHY_TO_PX(px)  (HI(px)) // PHYSICS TO PX UNITS

#define CSR_ENTITY_OFFSET_X         (ROOM_TXT_BOX_X + (ROOM_TXT_BOX_W >> 1) - 1) // bytes
#define CSR_ENTITY_OFFSET_Y         (ROOM_TXT_BOX_Y + (ROOM_TXT_BOX_H >> 1) - 2) // pixels
#define CSR_WORLD_TO_SCREEN_X(x)    (CSR_ENTITY_OFFSET_X + (CSR_PHY_TO_PX(x)))
#define CSR_WORLD_TO_SCREEN_Y(y)    (CSR_ENTITY_OFFSET_Y + (CSR_PHY_TO_PX(y)))

// PUBLIC
extern void csr_init(void);
extern void csr_update(void);