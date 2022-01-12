#include <cpctelera.h>
#include <sys/render/render.h>

#include <man/msg/msg.h>
#include <man/objs/objs.h>

void _render_printObjsInRoom(const TRoom *room) {
    u8 y_sprite = ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H - 24;

    // borra zona de sprites de objetos
    _render_clearBox(
        0,
        ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H - (3 * 24), // 24 * max objs in room - 1
        6,
        24 * 3
    );

    if (man_rooms_isExplored(room) && !man_rooms_isDark(room)) {
        TObj *(*obj) = man_objs_getInRoom(room);
        while ( (*obj) != 0) {
            TObj *current = *obj;

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