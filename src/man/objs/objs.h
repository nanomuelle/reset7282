#ifndef RESET_MAN_OBJS
#define RESET_MAN_OBJS

#include <cpctelera.h>
#include <man/rooms/rooms.h>

#define MAN_OBJS_SIZE 10

typedef enum ObjEnum {
    OBJ_ID_LIGHT,
    OBJ_ID_RAQUETA,
    OBJ_ID_CONSOLA,
    OBJ_ID_NULL
} TObjEnum;

#define OBJ_ATTR_CAN_TAKE 0x01 // 0b00000001
#define OBJ_ATTR_CAN_USE  0x02 // 0x00000010
typedef struct ObjStruct {
    const   TObjEnum    id;        // identificador del objeto
    const   u8*         name;      // nombre del objeto
            TRoomIdEnum roomId;    // habitacion en la que se encuentra el objeto
            u8          attrs;     // atributos
} TObj;

// PRIVATE
extern TObj _objs[MAN_OBJS_SIZE];

// PUBLIC
extern void man_objs_init(void);
extern TObj* man_objs_getPtr(void);
extern u8 man_objs_isInRoom(TObjEnum objId, TRoomIdEnum roomId);
extern void man_objs_moveToRoom(TObjEnum objId, TRoomIdEnum roomId);
extern TObj* man_objs_getObj(TObjEnum id);
extern TObj** man_objs_getInRoom(TRoom *room);
extern TObj *man_objs_findByName(const u8* objName);

// extern const u8* OBJ_NAME_RAQUETA;

#endif