#include <cpctelera.h>
#include <sys/render/render.h>

#include <man/msg/msg.h>
#include <man/objs/objs.h>

void _render_printObjsInInventory(void) {
    TRoom *inventory = man_rooms_getRoom(ROOM_ID_INVENTARIO);
    TObj *(*obj) = man_objs_getInRoom(inventory);
    u8 x = 80;

    u8 color = cpct_px2byteM1(0, 0, 0, 0);
    _render_clearBox(80 - (3 * 6), 200 - 24, (3 * 6), 24, color);

    while ( (*obj) != 0) {
        x -= 6;
        cpct_drawSprite(
            (*obj)->sprite,
            cpct_getScreenPtr(CPCT_VMEM_START, x, 200 - 24),
            6,
            24
        );
        ++obj;
    }
}