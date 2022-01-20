#pragma once

#include <types.h>
#include <sys/debug/debug.h>

#define CME_BUFFER_SIZE 51

// state
#define CME_ENTITY_STATE_INVALID  ( 0b00000000 )  // invalid
#define CME_ENTITY_STATE_DEAD     ( 0b10000000 )  // dead
#define CME_ENTITY_STATE_DEFAULT  ( 0b01111111 )  // default

// components
#define CME_ENTITY_COMPONENT_PHYSICS  ( 0b00000001 )  // has physics component
#define CME_ENTITY_COMPONENT_RENDER   ( 0b00000010 )  // has render component
#define CME_ENTITY_COMPONENT_AI       ( 0b00000100 )  // has render component

typedef u8 TEntityId;

typedef struct EntityStruct {
    TEntityId id;          // uid for the entity
    u8 state;       // state
    u8 components;  // component marks

    // PHYSICS COMPONENT
    i16 world_x;          // position
    i16 world_y;          //   byte alto para pintar, 2 bytes para physics
    i16 world_w;          // physic size
    i16 world_h;
    i16 world_vx;         // vx
    i16 world_vy;         // vy

    // RENDER COMPONENT
    u8 *pmem;       // PTR a ultima posición de memoria en que se pinto
    u8 render_w;    // render size
    u8 render_h;
    u8* sprite;     // sprite ptr
    u8* sprite_bg;  // sprite bg ptr

    // AI COMPONENT
    void (*ai)(void *self);
} TEntity;

typedef void (*TEntityCallback)(TEntity *);
typedef u8   (*TEntityUntilCallback)(TEntity *);

// PRIVATE
extern TEntity  m_cme_buffer[CME_BUFFER_SIZE];
// extern u8       m_man_entity_reservedEntities; // num of reserved entities
extern u8       m_cme_validEntities;    // num of valid entities
extern TEntity *m_cme_nextFree;         // ptr to the next free entity
// extern u8       m_cme_nextFreeIndex;    // index of the next free entity
extern u8       m_cme_isDirty;          // flag: 1.- needs update, 0.- do not needs update

// PUBLIC
extern void     cme_init         (void);
extern TEntity* cme_create       (void);
extern void     cme_set4destroy  (TEntity *);
extern void     cme_destroy      (TEntity *);
extern void     cme_forAll       (TEntityCallback);
extern void     cme_forEachUntil (TEntityUntilCallback);
extern TEntity* cme_getById      (TEntityId);
