#include <conversational/man/game/game.h>
#include <man/game/game.h>
#include <man/rooms/rooms.h>
#include <man/history/history.h>

#include <sys/parser/parser.h>
#include <sys/render/render.h>

TAction* _parsePrompt(void) {
    TPrompt *prompt = man_prompt_getPrompt();
    man_history_addUserInput(prompt->buffer);
    return sys_parser_parseAction(prompt->buffer);
}

void conversational_man_game_update(void) {
    _game_action = _parsePrompt();
    _game_execute_action(_game_action, man_rooms_getCurrentRoom());
    man_prompt_reset();
}