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
#define EEM_COMPONENT_ANIM     ( 0b00000100 )  // has anim component
#define EEM_COMPONENT_AI       ( 0b00001000 )  // has ai component

// states
#define EEM_STATE_INVALID     ( 0b00000000 )  // invalid
#define EEM_STATE_DEAD        ( 0b10000000 )  // dead (set for destroy)
#define EEM_STATE_VALID       ( 0b00000001 )  // valid entity
#define EEM_STATE_SOLID       ( 0b00000010 )  // can be collided against
#define EEM_STATE_MOVED       ( 0b00000100 )  // entity has change its position
#define EEM_STATE_REDRAW      ( 0b00001000 )  // needs redraw
// #define EEM_STATE_COLLISION   ( 0b00010000 )  // has collide

#define EEM_STATE_DEFAULT           ( EEM_STATE_VALID )     // default

#define EEM_STATE_VALID_MASK        ( ~EEM_STATE_VALID )    //
#define EEM_STATE_SOLID_MASK        ( ~EEM_STATE_SOLID )    //
#define EEM_STATE_MOVED_MASK        ( ~EEM_STATE_MOVED )    //
#define EEM_STATE_REDRAW_MASK       ( ~EEM_STATE_REDRAW )   //
// #define EEM_STATE_COLLISION_MASK    ( ~EEM_STATE_COLLISION )//


// state
typedef u8 TEEM_state;

// world 
typedef struct EEM_world_tr_struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 x2;
    u16 y2;
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
    u8 _screen_tr_unused5;
    u8 x2;
    u8 _screen_tr_unused6;
    u8 y2;
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
    TEEM_ai ai;
} TEEM_entity;

typedef void (*TEEM_callback)(TEEM_entity *);
typedef void (*TEEM_callback_pair)(TEEM_entity*, TEEM_entity*);

typedef struct EEM_moved_entity_struct {
    TEEM_entity* e;
} TEEM_moved_entity;
typedef void (*TEEM_movedCallback)(TEEM_moved_entity *);

typedef struct EEM_redraw_entity_struct {
    TEEM_entity* e;
} TEEM_redraw_entity;
typedef void (*TEEM_redrawCallback)(TEEM_redraw_entity *);

typedef struct EEM_dead_entity_struct {
    TEEM_entity* e;
} TEEM_dead_entity;
typedef void (*TEEM_deadCallback)(TEEM_dead_entity *);

// PRIVATE
extern TEEM_entity  m_eem_buffer[EEM_BUFFER_SIZE];
extern TEEM_state   m_eem_buffer_eof;         // marca de final del buffer
extern u8           m_eem_num_valid_entities; // num of valid entities
extern TEEM_entity* m_eem_next_free;          // ptr to the next free entity

// LIST OF ENTITIES BY STATE. THEY ARE FILLED AND RESET EACH FRAME.
extern TEEM_moved_entity    m_eem_moved_buffer[EEM_BUFFER_SIZE];    // TODO: adjust buffer size for moved entities
extern TEEM_moved_entity*   m_eem_moved_next_free;
extern u8                   m_eem_moved_num;

extern TEEM_redraw_entity   m_eem_redraw_buffer[EEM_BUFFER_SIZE];   // TODO: adjust buffer size for redraw entities
extern TEEM_redraw_entity*  m_eem_redraw_next_free;
extern u8                   m_eem_redraw_num;

extern TEEM_dead_entity     m_eem_dead_buffer[EEM_BUFFER_SIZE];     // TODO: adjust buffer size for dead entities
extern TEEM_dead_entity*    m_eem_dead_next_free;
extern u8                   m_eem_dead_num;

// PUBLIC
extern void         eem_init                (void);
extern TEEM_entity* eem_create              (void);
extern void         eem_for_all             (TEEM_callback);
extern void         eem_for_all_reversed    (TEEM_callback);
extern void         eem_for_pairs           (TEEM_callback_pair callback, u8 state_mask1, u8 state_mask2);
extern TEEM_entity* eem_get_by_id           (u8);
extern void         eem_destroy             (TEEM_entity *);
// #define eem_reset_state_moved(entity_ptr)   (entity_ptr)->state &= EEM_STATE_MOVED_MASK

// moved entities
extern void               eem_resetMoved        (void);
extern TEEM_moved_entity* eem_createMoved       (void);
extern void               eem_forEachMoved      (TEEM_movedCallback);
extern void               eem_set_state_moved   (TEEM_entity *);

// redraw entities
extern void                eem_resetRedraw      (void);
extern TEEM_redraw_entity* eem_createRedraw     (void);
extern void                eem_forEachRedraw    (TEEM_redrawCallback);
extern void                eem_set_state_redraw (TEEM_entity *);

// dead entities
extern void                eem_resetDead        (void);
extern TEEM_dead_entity*   eem_createDead       (void);
extern void                eem_forEachDead      (TEEM_deadCallback);
extern void                eem_set_state_dead   (TEEM_entity *);
