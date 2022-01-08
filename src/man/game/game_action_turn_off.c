#include <cpctelera.h>

#include <man/game/game.h>
#include <man/rooms/rooms.h>
#include <man/history/history.h>

#include <sys/parser/parser.h>
#include <sys/str/str.h>

const u8* const ACTION_TURN_OFF_MSG[] = {
    "no se como apagar eso",
    "fuera luces",
    "la luz ya esta apagada"
};

void _game_action_turn_off(TAction* action, TRoom* room) {
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addError(ACTION_TURN_OFF_MSG[0]);
        return;
    }

    if (action->param1.obj_param == OBJ_ID_LIGHT) {
        if (!man_rooms_isDark(room)) {
            man_rooms_switchDark(room);
            man_history_addResponse(ACTION_TURN_OFF_MSG[1]);
        } else {
            man_history_addResponse(ACTION_TURN_OFF_MSG[2]);
        }
    }
}