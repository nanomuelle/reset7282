#include<cpctelera.h>
#include<sys/action/action.h>

#include <sys/debug/debug.h>

typedef struct {
    u8* name;
} TActionDefinition;

const TActionDefinition actionDefs[] = {
    { "ir" },
    { "buscar"},
    { "orden desconocida" }
};

const u8* sys_action_getActionName(TAction* action) {    
    return actionDefs[action->type].name;
}

void sys_action_init(void) {}