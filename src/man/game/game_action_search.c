#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/objs/objs.h>
#include <man/msg/msg.h>

#include <sys/parser/parser.h>

void _game_action_search(TAction* action, TRoom* room) {
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

    if (count == 0) {
        man_history_addWarning(" -> no encuentras nada");
    }
}