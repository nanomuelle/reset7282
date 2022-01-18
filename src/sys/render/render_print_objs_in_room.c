#include <cpctelera.h>
#include <sys/render/render.h>

#include <man/msg/msg.h>
#include <man/objs/objs.h>

#define MAX_OBJS_IN_ROOM    ( 3 )
#define OBJ_IN_ROOM_W       ( 6 )  // bytes (24 pixels)
#define OBJ_IN_ROOM_H       ( 24 ) // pixels
#define OBJS_IN_ROOM_X      ( 0 )  // bytes
#define OBJS_IN_ROOM_W      ( 7 )  // bytes
#define OBJS_IN_ROOM_H      ( MAX_OBJS_IN_ROOM * OBJ_IN_ROOM_H )            // pixels
#define OBJS_IN_ROOM_Y      ( ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H - OBJS_IN_ROOM_H ) // pixels

void _render_printObjsInRoom(const TRoom *room) {
    u8 y_sprite = OBJS_IN_ROOM_Y + OBJS_IN_ROOM_H - OBJ_IN_ROOM_H;

    // borra zona de sprites de objetos
    _render_clearBox(
        OBJS_IN_ROOM_X,
        OBJS_IN_ROOM_Y,
        OBJS_IN_ROOM_W,
        OBJS_IN_ROOM_H
    );

    if (man_rooms_isExplored(room) && !man_rooms_isDark(room)) {
        TObj *(*obj) = man_objs_getInRoom(room);
        while ( (*obj) != 0) {
            TObj *current = *obj;

            cpct_drawSprite(
                current->sprite,
                cpct_getScreenPtr(CPCT_VMEM_START, OBJS_IN_ROOM_X + 1, y_sprite),
                OBJ_IN_ROOM_W,
                OBJ_IN_ROOM_H
            );

            y_sprite -= 24;
            ++obj;
        }
    }
}