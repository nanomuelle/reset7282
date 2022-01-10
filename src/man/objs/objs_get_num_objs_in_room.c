#include <man/objs/objs.h>

#include <sys/debug/debug.h>
#include <sys/debug/debug.h>

u8 man_objs_getNumObjsInRoom(TRoomIdEnum roomId) {
    TObj *obj = man_objs_getPtr();
    u8 num = 0;

    for(u8 i = 0; i < MAN_OBJS_SIZE; i++) {
        if (obj->roomId == roomId) {
            ++num;
        }
        ++obj;
    }

    return num;
}