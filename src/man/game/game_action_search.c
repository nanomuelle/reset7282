#include <cpctelera.h>

#include <man/game/game.h>

#include <man/history/history.h>
#include <man/objs/objs.h>

const u8* const ACTION_SEARCH_MSG[] = {
    "no encuentras nada mas",
    "no encuentras nada",
    "a oscuras, no encuentras nada"
};

void _game_action_search(TAction* action, TRoom* room) {
    u8* msg = 0;

    if (man_rooms_isDark(room)) {
        msg = ACTION_SEARCH_MSG[2];
    } else if (man_rooms_isExplored(room)) {
        msg = ACTION_SEARCH_MSG[0];
    } else {
        u8 count = _game_show_objs_in_room(room);
        if (count == 0) {
            msg = ACTION_SEARCH_MSG[1];
        }
        man_rooms_setExplored(room);
    }

    if (msg != 0) {
        man_history_addResponse(msg);
    }
}