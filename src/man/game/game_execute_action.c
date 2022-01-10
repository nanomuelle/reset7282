#include <man/game/game.h>
#include <sys/parser/parser.h>

#include <sys/debug/debug.h>

typedef struct ActionRunnerStruct {
    const TActionType type;
    const TActionRunnerFn runner;
} TActionRunner;

#define NUM_ACTION_RUNNERS 10

const TActionRunner _actionRunners[NUM_ACTION_RUNNERS] = {
    { ACTION_TYPE_DROP, _game_action_drop },
    { ACTION_TYPE_EXAMINE, _game_action_examine },
    { ACTION_TYPE_GO, _game_action_go },
    { ACTION_TYPE_INVENTORY, _game_action_inventory },
    { ACTION_TYPE_SEARCH, _game_action_search },
    { ACTION_TYPE_TAKE, _game_action_take },
    { ACTION_TYPE_TURN_OFF, _game_action_turn_off },
    { ACTION_TYPE_TURN_ON, _game_action_turn_on },
    { ACTION_TYPE_UNKNOWN, _game_action_unknown },
    { ACTION_TYPE_USE, _game_action_use }
};

TActionRunnerFn _game_action_getRunner(TActionType type) {
    TActionRunner* actionRunner = _actionRunners;
    while (actionRunner->type != type) {
        ++actionRunner;
    }
    return actionRunner->runner;
}

void _game_execute_action(TAction* action, TRoom *room) {
    TActionRunnerFn runner = _game_action_getRunner(action->type);
    // TActionRunner runner = _runners[action->type];
    runner(action, room);
}