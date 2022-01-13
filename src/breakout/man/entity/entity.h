#ifndef BREAKOUT_MAN_ENTITY
#define BREAKOUT_MAN_ENTITY

#include <breakout/breakout.h>

typedef struct BreakoutEntityStruct {
    TBreakoutEntityId id;   // id
    i16 x;   // position
    i16 y;   // byte alto para pintar, 2 bytes para physics
    i16 w;   // physic size
    i16 h;
    i16 vx;   // velocity
    i16 vy;
    u8 render_w;    // render size
    u8 render_h;
    u8* sprite;     // sprite ptr
    u8 *pmem; // PTR a ultima posición de memoria en que se pinto
    void (*ai)(void *self);
} TBreakoutEntity;

typedef void (*TBreakoutEntityCallback)(TBreakoutEntity *);

// PRIVATE
extern TBreakoutEntity  _breakout_man_entity_buffer[];
extern u8               _breakout_man_entity_numEntities;

// PUBLIC
extern void             breakout_man_entity_init    (void);
extern TBreakoutEntity* breakout_man_entity_create  (void);
extern TBreakoutEntity* breakout_man_entity_getById (TBreakoutEntityId id);
extern void             breakout_man_entity_forEach (TBreakoutEntityCallback);

#endif