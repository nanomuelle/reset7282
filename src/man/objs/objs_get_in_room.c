#include <man/objs/objs.h>

#include <sys/debug/debug.h>

TObj* _objsInRoomBuffer[MAN_OBJS_SIZE];

void _clearObjsInRoomBuffer(void) {
    cpct_memset(_objsInRoomBuffer, 0, MAN_OBJS_SIZE * sizeof(TObj*));
}

TObj** man_objs_getInRoom(TRoom *room) {
    TObj *src = man_objs_getPtr();
    TObj *(*dst) = _objsInRoomBuffer;

    _clearObjsInRoomBuffer();
    for(u8 i = 0; i < MAN_OBJS_SIZE; i++) {
        if (src->roomId == room->id) {
            *dst = src;
            ++dst;
        }
        ++src;
    }

    return _objsInRoomBuffer;
}