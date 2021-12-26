#ifndef PONG_MAN_ENTITY
#define PONG_MAN_ENTITY

#include <cpctelera.h>

#define PONG_MAN_ENTITY_BUFFER_SIZE 3

typedef struct PongEntityStruct {
    u8 x;   // position
    u8 y;
    u8 w;   // size
    u8 h;
    u8 vx;  // velocity
    u8 vy;
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