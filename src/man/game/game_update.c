#include <string.h>

#include <man/game/game.h>
#include <man/rooms/rooms.h>
#include <man/history/history.h>

#include <sys/action/action.h>
#include <sys/render/render.h>

#include <sys/debug/debug.h>

void _updateHistory(TAction* action) {
    u8 buffer[HISTORY_LINE_SIZE] = "\0";
    strcat(buffer, sys_action_getActionName(action));
    strcat(buffer, " ");
    strcat(buffer, &action->param1);
    man_history_addLine(buffer, 2);
}

TAction* _parsePrompt(void) {
    TPrompt *prompt = man_prompt_getPrompt();
    return sys_action_parse(prompt->buffer);
}

void man_game_update(void) {
    TAction *action = _parsePrompt();

    sys_debug_info("man_game_update -> action type", 0, 190);
    sys_debug_waitKey();
    sys_debug_number(action->type, 0, 190);
    sys_debug_waitKey();
    
    _game_execute_action(action, man_rooms_getCurrentRoom());
    _updateHistory(action);

    man_prompt_reset();
}