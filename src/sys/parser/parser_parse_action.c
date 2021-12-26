#include <cpctelera.h>

#include <man/prompt/prompt.h>

#include <sys/parser/parser.h>
#include <sys/ascii/ascii.h>
#include <sys/str/str.h>

#include <sys/debug/debug.h>

#define ACTION_USERINPUT_TO_TYPE_SIZE 15

const TUserInputToActionMap userInputToActionMap[ACTION_USERINPUT_TO_TYPE_SIZE] = {
    { "ir",         { ACTION_TYPE_GO     , { .unknown_param = ACTION_PARAM_UNKNOWN }}},
    { "n",          { ACTION_TYPE_GO     , { .go_param = ACTION_PARAM_GO_N       }}},
    { "s",          { ACTION_TYPE_GO     , { .go_param = ACTION_PARAM_GO_S       }}},
    { "e",          { ACTION_TYPE_GO     , { .go_param = ACTION_PARAM_GO_E       }}},
    { "o",          { ACTION_TYPE_GO     , { .go_param = ACTION_PARAM_GO_O       }}},

    { "inventario", { ACTION_TYPE_INVENTORY, { .unknown_param = ACTION_PARAM_UNKNOWN }}},
    { "i",          { ACTION_TYPE_INVENTORY, { .unknown_param = ACTION_PARAM_UNKNOWN }}},

    { "buscar",     { ACTION_TYPE_SEARCH , { .unknown_param = ACTION_PARAM_UNKNOWN  }}},
    { "mirar",      { ACTION_TYPE_SEARCH , { .unknown_param = ACTION_PARAM_UNKNOWN  }}},
    { "explorar",   { ACTION_TYPE_SEARCH , { .unknown_param = ACTION_PARAM_UNKNOWN  }}},

    { "coger",      { ACTION_TYPE_TAKE   , { .unknown_param = ACTION_PARAM_UNKNOWN }}},
    { "raqueta",    { ACTION_TYPE_TAKE   , { .obj_param = OBJ_ID_RAQUETA }}},

    { "encender",   { ACTION_TYPE_TURN_ON, { .unknown_param = ACTION_PARAM_UNKNOWN }}},
    { "dar",        { ACTION_TYPE_TURN_ON, { .unknown_param = ACTION_PARAM_UNKNOWN }}},
    { "luz",        { ACTION_TYPE_TURN_ON, { .obj_param = OBJ_ID_LIGHT }}},
};

TAction action;

//
// INPUT:
//   u8 *userInput -> puntero a la texto escrito por el usuario
//   TAction *action -> puntero a la accion en la que se guardara el typo
//
// OUTPUT:
//   escribe en action->type en tipo de action
//   u8 * -> puntero al principio de la segunda palabra (que se usara como param en el action)
//
u8* _parseActionType(u8* userInput, TAction *action) {
    u8 buffer[PROMPT_BUFFER_SIZE];

    userInput = sys_str_copyNextWord(userInput, buffer);

    for (u8 i = 0; i < ACTION_USERINPUT_TO_TYPE_SIZE; i++) {
        TUserInputToActionMap *itemMap = &userInputToActionMap[i];
        if (sys_str_isEqual(itemMap->txt, buffer)) {
            cpct_memcpy(action, &(itemMap->action), sizeof(TAction));
            break;
        }
    }

    return userInput;
}

//
// INPUT:
//   u8 *userInput -> puntero al param escrito por el usuario
//   TAction *action -> puntero a la accion en la que se guardara el param
//
// OUTPUT:
//   escribe en action->type en tipo de action
//   u8 * -> puntero al principio de la segunda palabra (que se usara como param en el action)
//
void _parseActionParam(u8* userInput, TAction *action) {
    u8 buffer[PROMPT_BUFFER_SIZE];

    // copy until find an space or a null
    sys_str_copyNextWord(userInput, buffer);

    switch(action->type) {
        case ACTION_TYPE_GO:
            _sys_parser_parseParamGo(buffer, action);
            break;

        case ACTION_TYPE_TAKE:
        case ACTION_TYPE_TURN_ON:
            _sys_parser_parseParamObj(buffer, action);
            break;
    }
}

TAction *sys_parser_parseAction(u8* buffer) {
    u8* paramPtr;
    action.type = ACTION_TYPE_UNKNOWN;
    action.param1.unknown_param = ACTION_PARAM_UNKNOWN;

    paramPtr = _parseActionType(buffer, &action);

    if (action.param1.unknown_param == ACTION_PARAM_UNKNOWN) {
        _parseActionParam(paramPtr, &action);
    }

    return &action;
}
