#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/objs/objs.h>
#include <man/msg/msg.h>

u8 _game_show_objs_in_room(TRoom *room) {
    u8 count = 0;
    TObj *(*obj) = man_objs_getInRoom(room);

    while ( (*obj) != 0) {
        u8 *msg = man_msg_clear();
        man_msg_concat("-> ");
        man_history_addWarning( 
            man_msg_concat( (*obj)->name )
        );
        ++obj;
        ++count;
    }

    return count;
}