#include <cpctelera.h>

#include <man/game/game.h>

#include <man/history/history.h>
#include <man/objs/objs.h>

void _game_action_search(TAction* action, TRoom* room) {
    u8 count = _game_show_objs_in_room(room);
    if (count == 0) {
        man_history_addResponse("no encuentras nada");
    }
}