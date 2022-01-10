#include <cpctelera.h>
#include <sys/render/render.h>

#include <man/msg/msg.h>
#include <man/objs/objs.h>

void _render_printObjsInRoom(const TRoom *room, const u8 x, const u8 y) {
    u8 x_right = x;
    u8 y_sprite = ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H - 24;

    // borra zona de txt objetos
    _render_clearBox(
        ROOM_TXT_BOX_X + 1,
        ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H - LINE_HEIGHT,
        ROOM_TXT_BOX_W - 2,
        LINE_HEIGHT
    );

    // borra zona de sprites de objetos
    _render_clearBox(
        0,
        ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H - (2 * 24), // 24 * max objs in room
        6,
        24 * 2
    );

    if (man_rooms_isExplored(room) && !man_rooms_isDark(room)) {
        TObj *(*obj) = man_objs_getInRoom(room);
        while ( (*obj) != 0) {
            u8* msg = man_msg_clear();
            u8 pen = 0;
            TObj *current = *obj;

            man_msg_concat(current->name);

            if ((current->attrs & OBJ_ATTR_CAN_TAKE) == OBJ_ATTR_CAN_TAKE) {
                pen = 1;
            }

            if ((current->attrs & OBJ_ATTR_CAN_USE) == OBJ_ATTR_CAN_USE) {
                pen = 2;
            }

            x_right -= (2 * man_msg_getLength());
            _render_printMsg(msg, x_right, y, pen);
            x_right -= 2;

            // print sprite
            cpct_drawSprite(
                current->sprite,
                cpct_getScreenPtr(CPCT_VMEM_START, 0, y_sprite),
                6,
                24
            );

            y_sprite -= 24;
            ++obj;
        }
    }
}