#include <cpctelera.h>

#include <man/game/game.h>

#include <man/history/history.h>
#include <man/objs/objs.h>

void _game_action_search(TAction* action, TRoom* room) {
    if (man_rooms_isExplored(room)) {
        man_history_addResponse("no encuentras nada mas");
    } else {
        u8 count = _game_show_objs_in_room(room);
        if (count == 0) {
            man_history_addResponse("no encuentras nada");
        }
        man_rooms_setExplored(room);
    }
}