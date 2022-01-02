#include <man/game/game.h>
#include <sys/parser/parser.h>

#include <sys/debug/debug.h>

const TActionRunner _runners[] = {
    _game_action_examine,
    _game_action_go,
    _game_action_inventory,
    _game_action_search,
    _game_action_take,
    _game_action_turn_on,
    _game_action_unknown,
    _game_action_use
};

void _game_execute_action(TAction* action, TRoom *room) {
    TActionRunner runner = _runners[action->type];
    runner(action, room);
}