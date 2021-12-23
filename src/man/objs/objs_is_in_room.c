#include <man/objs/objs.h>

u8 man_objs_isInRoom(TObjEnum objId, TRoomIdEnum roomId) {
    TObj *obj = man_objs_getObj(objId);
    return obj->roomId == roomId ? 1 : 0;
}