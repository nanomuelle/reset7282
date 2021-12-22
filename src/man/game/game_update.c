#include <man/game/game.h>
#include <man/rooms/rooms.h>
#include <man/history/history.h>

#include <sys/action/action.h>
#include <sys/render/render.h>

#include <sys/debug/debug.h>

TAction* _parsePrompt(void) {
    TPrompt *prompt = man_prompt_getPrompt();
    return sys_action_parse(prompt->buffer);
}

void man_game_update(void) {
    TAction *action = _parsePrompt();
    _game_execute_action(action, man_rooms_getCurrentRoom());
    man_prompt_reset();
}