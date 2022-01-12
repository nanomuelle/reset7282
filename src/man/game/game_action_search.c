#include <cpctelera.h>

#include <man/game/game.h>

#include <man/history/history.h>
#include <man/objs/objs.h>

const u8* const ACTION_SEARCH_MSG[] = {
    "no encuentras nada",
    "a oscuras, no encuentras nada"
};

void _game_action_search(TAction* action, TRoom* room) {
    if (man_rooms_isDark(room)) {
        man_history_addResponse(ACTION_SEARCH_MSG[1]);
        return;
    }

    {
        u8 count = _game_show_objs_in_room(room);
        if (count == 0) {
            man_history_addResponse(ACTION_SEARCH_MSG[0]);
            return;
        }
    }

    man_rooms_setExplored(room);
}