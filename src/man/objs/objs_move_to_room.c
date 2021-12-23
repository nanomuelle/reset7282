#include <man/objs/objs.h>

void man_objs_moveToRoom(TObjEnum objId, TRoomIdEnum roomId) {
    TObj* obj = man_objs_getObj(objId);
    obj->roomId = roomId;
}