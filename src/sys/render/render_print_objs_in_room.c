#include <sys/render/render.h>

#include <man/msg/msg.h>
#include <man/objs/objs.h>

void _render_printObjsInRoom(TRoom *room, u8 x, u8 y, u8 pen) {
    TObj *(*obj) = man_objs_getInRoom(room);
    u8 *msg = man_msg_clear();
    while ( (*obj) != 0) {
        man_msg_concat(" ");
        man_msg_concat((*obj)->name);
        ++obj;
    }
    _render_printMsg(msg, x - (2 * man_msg_getLength()), y, pen);
}