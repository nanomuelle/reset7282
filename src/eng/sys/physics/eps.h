#pragma once

#include <types.h>
#include <eng/eng.h>

// EPS => ENGINE PHYSICS SYSTEM

// PHYSICS WORLD SIZE
// 0 <= x < 65536 (256 * 256)
// 0 <= y < 32768 (128 * 256)

#define EPS_PX_TO_WORLD(px)    ((u16) (px) << 8 ) // RENDER TO WORLD UNITS

#define EPS_WORLD_W            ((u16) EPS_PX_TO_WORLD(256))
#define EPS_WORLD_H            ((u16) EPS_PX_TO_WORLD(128))

#define EPS_WORLD_MIN_X        ((u16) 0 )
#define EPS_WORLD_MAX_X        ((u16) EPS_WORLD_W - 1 )
#define EPS_WORLD_MIN_Y        ((u16) 0 )
#define EPS_WORLD_MAX_Y        ((u16) EPS_WORLD_H - 1 )

#define EPS_MAX_ENTITIES       ((u8) 10)
#define EPS_INVALID_ENTITY     ((TEEM_entity*) 0x0000 )

// PRIVATE
extern TEEM_entity*  m_eps_entities[EPS_MAX_ENTITIES];
extern TEEM_entity*  m_eps_entities_eof;
extern TEEM_entity** m_eps_next_free_entity;

// PUBLIC
extern void eps_init(void);

extern void eps_add_entity      (TEEM_entity*);
extern void eps_remove_entity   (TEEM_entity*);

extern void eps_update(void);
extern u8   eps_check_collision(TEEM_entity *e1, TEEM_entity *e2);
