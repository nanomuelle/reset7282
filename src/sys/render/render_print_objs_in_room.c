#include <sys/render/render.h>

#include <man/msg/msg.h>
#include <man/objs/objs.h>
#include <sys/debug/debug.h>

void _render_printObjsInRoom(const TRoom *room, const u8 x, const u8 y) {
    TObj *(*obj) = man_objs_getInRoom(room);
    u8 x_right = x;

    while ( (*obj) != 0) {
        u8* msg = man_msg_clear();
        u8 pen = 0;

        man_msg_concat((*obj)->name);

        if (((*obj)->attrs & OBJ_ATTR_CAN_TAKE) == OBJ_ATTR_CAN_TAKE) {
            pen = 1;
        }

        if (((*obj)->attrs & OBJ_ATTR_CAN_USE) == OBJ_ATTR_CAN_USE) {
            pen = 2;
        }

        x_right -= (2 * man_msg_getLength());
        _render_printMsg(msg, x_right, y, pen);
        x_right -= 2;

        ++obj;
    }
}