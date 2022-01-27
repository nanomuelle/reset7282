#pragma once

#include <types.h>
#include <sys/debug/debug.h>

// IDEAS
// - marcar entidades como estáticas y que su ptr no se pueda mover en el buffer
//   se apilarían al principio del buffer
//   util para entidades siempre vivas, y asi poder mantener su ptr

#define EEM_BUFFER_SIZE 51

// components
#define EEM_COMPONENT_PHYSICS  ( 0b00000001 )  // has physics component
#define EEM_COMPONENT_RENDER   ( 0b00000010 )  // has render component
#define EEM_COMPONENT_ANIM     ( 0b00000100 )  // has render component
#define EEM_COMPONENT_AI       ( 0b00001000 )  // has render component

// state
typedef enum EEM_state_enum {
    EEM_STATE_INVALID    = 0b00000000,  // invalid
    EEM_STATE_DEAD       = 0b10000000,  // dead (set for destroy)
    EEM_STATE_MOVED      = 0b01000000,  // entity has change its position
    EEM_STATE_MOVED_MASK = 0b10111111,  // entity has change its position
    EEM_STATE_DEFAULT    = 0b01111111   // default
} TEEM_state;

// world 
typedef struct EEM_world_tr_struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} TEEM_world_tr;

typedef struct EEM_screen_tr_struct {
    u8 _screen_tr_unused1;
    u8 x;
    u8 _screen_tr_unused2;
    u8 y;
    u8 _screen_tr_unused3;
    u8 w;
    u8 _screen_tr_unused4;
    u8 h;
} TEEM_screen_tr;

typedef union EEM_tr_struct {
    TEEM_world_tr  world;
    TEEM_screen_tr screen;
} TEEM_tr;

typedef struct EEM_ph_struct {
    i16 vx;
    i16 vy;
} TEEM_ph;

typedef struct EEM_render_struct {
    u8 *pmem;       // PTR a ultima posición de memoria en que se pinto
    u8 shift;       // ultimo pixel offset (necesario para restaurar el bg)
    u8 w;           // render width  in bytes! (1 byte = 4 px in MODE 1)
    u8 h;           // render height in bytes! (coincide con px)
    u8** sprite;    // preshifted sprite ptr
    u8* sprite_bg;  // sprite ptr to background storage
} TEEM_render;

typedef void (*TEEM_ai)(void *self);

typedef struct EEM_entity_struct {
    u8 id;          // uid for the entity
    u8 state;       // state
    u8 components;  // component marks

    // POSITION and SIZE
    TEEM_tr tr;

    // PHYSICS COMPONENT (velocity)
    TEEM_ph ph;

    // RENDER COMPONENT
    TEEM_render render;

    // AI COMPONENT
    TEEM_ai ai;              // void (*ai)(void *self);
} TEEM_entity;

typedef void (*TEEM_callback)(TEEM_entity *);
// typedef u8   (*TEntityUntilCallback)(TEntity *);

// PRIVATE
extern TEEM_entity  m_eem_buffer[EEM_BUFFER_SIZE];
extern TEEM_state   m_eem_buffer_eof;         // marca de final del buffer
extern u8           m_eem_num_valid_entities; // num of valid entities
extern TEEM_entity* m_eem_next_free;          // ptr to the next free entity
extern u8           m_eem_needs_update;       // flag: 1.- needs update, 0.- do not needs update

// PUBLIC
extern void         eem_init          (void);
extern TEEM_entity* eem_create        (void);
extern void         eem_destroy           (TEEM_entity *);
extern void         eem_for_all            (TEEM_callback);
extern void         eem_for_all_reversed    (TEEM_callback);
extern TEEM_entity* eem_get_by_id           (u8);

extern  void         eem_kill              (TEEM_entity *);
#define eem_set_state_moved(entity_ptr)      (entity_ptr)->state |= EEM_STATE_MOVED
#define eem_reset_state_moved(entity_ptr)    (entity_ptr)->state &= EEM_STATE_MOVED_MASK
