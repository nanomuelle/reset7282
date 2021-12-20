#include<cpctelera.h>
#include<man/action/action.h>

TAction currentAction;

typedef struct {
    u8* name;
} TActionDefinition;

const TActionDefinition actionDefs[] = {
    { "ir" },
    { "buscar"},
    { "orden desconocida" }
};

const u8* man_action_getActionName(TAction* action) {
    return actionDefs[action->type].name;
}

void man_action_init(void) {
    man_action_reset();
}

TAction* man_action_getCurrentAction() {
    return &currentAction;
}

void man_action_reset() {
    currentAction.type = ACTION_NULL;
    currentAction.param1 = 0xFF;
}




