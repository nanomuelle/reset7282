#ifndef PONG_MAN_ENTITY
#define PONG_MAN_ENTITY

#include <cpctelera.h>
#include <globals.h>

#define PONG_MAN_ENTITY_BUFFER_SIZE 3

typedef struct PongEntityStruct {
    i16 x;   // position
    i16 y;   // byte alto para pintar, 2 bytes para physics
    u16 w;   // physic size
    u16 h;
    i16 vx;   // velocity
    i16 vy;
    u8 render_w;    // render size
    u8 render_h;
    u8 color;
    u8 *pmem; // PTR a ultima posicion de memoria en que se pinto
} TPongEntity;

typedef void (*TPongEntityCallback)(TPongEntity *);

// PRIVATE
extern TPongEntity _pong_man_entity_buffer[];
extern u8          _pong_man_entity_numEntities;

// PUBLIC
extern void         pong_man_entity_init    (void);
extern TPongEntity* pong_man_entity_create  (void);
extern void         pong_man_entity_forEach (TPongEntityCallback);

#endif