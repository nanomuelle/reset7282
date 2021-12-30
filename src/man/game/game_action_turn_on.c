#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>

#include <sys/parser/parser.h>
#include <sys/str/str.h>

const u8* const ACTION_TURN_ON_MSG[] = {
    "no se como encender eso",
    "y la luz se hizo",
    "la luz ya esta encendida"
};

void _game_action_turn_on(TAction* action, TRoom* room) {
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addError(ACTION_TURN_ON_MSG[0]);
        return;
    }

    if (action->param1.obj_param == OBJ_ID_LIGHT) {
        if (man_rooms_isDark(room)) {
            man_rooms_unsetDark(room);
            man_history_addResponse(ACTION_TURN_ON_MSG[1]);
        } else {
            man_history_addResponse(ACTION_TURN_ON_MSG[2]);
        }
    }
}