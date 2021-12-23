#ifndef RESET_MAN_OBJS
#define RESET_MAN_OBJS

#include <cpctelera.h>
#include <man/rooms/rooms.h>

#define MAN_OBJS_SIZE 10

typedef enum ObjEnum {
    OBJ_ID_RAQUETA,
    OBJ_ID_CONSOLA,
    OBJ_ID_NULL
} TObjEnum;

typedef struct ObjStruct {
    TObjEnum     id;        // identificador del objeto
    u8*          name;      // nombre del objeto
    TRoomIdEnum  roomId;    // habitacion en la que se encuentra el objeto
} TObj;

// PRIVATE
extern TObj _objs[MAN_OBJS_SIZE];

// PUBLIC
extern void man_objs_init(void);
extern TObj* man_objs_getPtr(void);
extern TObj* man_objs_getObj(TObjEnum id);
extern TObj** man_objs_getInRoom(TRoom *room);

#endif