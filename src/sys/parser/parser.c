#include<cpctelera.h>
#include <sys/parser/parser.h>

#include <sys/debug/debug.h>

typedef struct {
    u8* name;
} TActionDefinition;

const TActionDefinition actionDefs[] = {
    { "ir" },
    { "buscar"},
    { "encender" },
    { "orden desconocida" }
};

const u8* sys_parser_getActionName(TAction* action) {    
    return actionDefs[action->type].name;
}

void sys_parser_init(void) {}