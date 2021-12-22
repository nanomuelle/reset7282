#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/msg/msg.h>

#include <sys/action/action.h>
#include <sys/str/str.h>

void _game_action_turn_on(TAction* action, TRoom* room) {
    TParamTurnOnEnum object = action->param1.turn_on_param;

    u8* msg = man_msg_clear();
    man_msg_concat("encender");

    if (object == ACTION_PARAM_TURN_ON_UNKNOWN) {
        man_history_addInfo(msg);
        man_history_addError(" -> encender el que?");
    }
}