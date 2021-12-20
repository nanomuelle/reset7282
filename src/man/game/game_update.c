#include <string.h>

#include <man/game/game.h>
#include <man/action/action.h>
#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <sys/render/render.h>

#include <sys/debug/debug.h>

void updateHistory(TAction* action) {
    u8 buffer[HISTORY_LINE_SIZE] = "\0";
    strcat(buffer, man_action_getActionName(action));
    strcat(buffer, " ");
    strcat(buffer, &action->param1);
    man_history_addLine(buffer, 2);
}

void man_game_update(void) {
    TAction* action = man_action_getCurrentAction();

    if (action->type == ACTION_NULL ) {
        return;
    }

    man_action_execute(action, man_rooms_getCurrentRoom());
    updateHistory(action);

    man_action_reset();
    man_prompt_reset();
}