#include <man/game/game.h>
#include <sys/action/action.h>

#include <sys/debug/debug.h>

const TActionRunner _runners[] = {
    _game_action_go,
    _game_action_search,
    _game_action_unknown
};

void _game_execute_action(TAction* action, TRoom *room) {
    TActionRunner runner = _runners[action->type];
    runner(action, room);
}