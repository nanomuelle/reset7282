#pragma once
// CSP => CONSOLE SYSTEM PHYSICS

#include <globals.h>
#include <console/console.h>

// PHYSICS WORLD

// (-HALF_W, -HALF_H) ... (0, -HALF_H) ... (HALF_W, -HALF_H)
//        ...              ...                   ...
// (-HALF_W,       0) ... (0, 0)       ... (HALF_W,       0)
//        ...              ...                   ...
// (-HALF_W,  HALF_H) ... (0,  HALF_H) ... (HALF_W,  HALF_H)

#define CSP_PX_TO_WORLD(px)    ((u16) (px) << 8 ) // RENDER TO WORLD UNITS

#define CSP_WORLD_W            ((u16) CSP_PX_TO_WORLD( M1_BYTES_TO_PX(ROOM_TXT_BOX_W) - 1) )
#define CSP_WORLD_H            ((u16) CSP_PX_TO_WORLD( ROOM_TXT_BOX_H ) )

// #define CSP_WORLD_MIN_X        ((i16) (-CSP_WORLD_W / 2) + CSP_PX_TO_WORLD(1) )
// #define CSP_WORLD_MAX_X        ((i16) ( CSP_WORLD_W / 2) - CSP_PX_TO_WORLD(1) )
// #define CSP_WORLD_MIN_Y        ((i16) (-CSP_WORLD_H / 2) + CSP_PX_TO_WORLD(2) )
// #define CSP_WORLD_MAX_Y        ((i16) ( CSP_WORLD_H / 2) + CSP_PX_TO_WORLD(1) )

#define CSP_WORLD_MIN_X        ( 0 )
#define CSP_WORLD_MAX_X        ( CSP_WORLD_W - 1 )
#define CSP_WORLD_MIN_Y        ( 0 )
#define CSP_WORLD_MAX_Y        ( CSP_WORLD_H - 1 )

#define CSP_MAX_ENTITIES       10
#define CSP_INVALID_ENTITY     0x0000

// PRIVATE
extern TEntity* m_csp_entities[CSP_MAX_ENTITIES + 1];
extern TEntity **m_csp_next_free_entity;

extern void  csp_addEntity(TEntity *entity);
extern void  csp_removeEntity(TEntity *entity);

// PUBLIC
extern void csp_init(void);
extern void csp_update(void);
extern u8   csp_checkCollision(TEntity *ent1, TEntity *ent2);
