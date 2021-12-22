#include <cpctelera.h>

#include <man/prompt/prompt.h>
#include <man/rooms/rooms.h>

#include <sys/action/action.h>
#include <sys/ascii/ascii.h>
#include <sys/str/str.h>

#define ACTION_USERINPUT_TO_TYPE_SIZE 10

TAction action;

const TUserInputToActionMap userInputToActionMap[ACTION_USERINPUT_TO_TYPE_SIZE] = {
    { "ir",         { ACTION_TYPE_GO     , ACTION_PARAM_UNKNOWN } },
    { "n",          { ACTION_TYPE_GO     , ACTION_PARAM_DIR_N   } },
    { "s",          { ACTION_TYPE_GO     , ACTION_PARAM_DIR_S   } },
    { "e",          { ACTION_TYPE_GO     , ACTION_PARAM_DIR_E   } },
    { "o",          { ACTION_TYPE_GO     , ACTION_PARAM_DIR_O   } },
    { "buscar",     { ACTION_TYPE_SEARCH , ACTION_PARAM_UNKNOWN } },
    { "mirar",      { ACTION_TYPE_SEARCH , ACTION_PARAM_UNKNOWN } },
    { "explorar",   { ACTION_TYPE_SEARCH , ACTION_PARAM_UNKNOWN } },
    { "luz",        { ACTION_TYPE_TURN_ON, ACTION_PARAM_TURN_ON_LIGHT } },
    { "encender",   { ACTION_TYPE_TURN_ON, ACTION_PARAM_UNKNOWN       } },
};

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

    // TODO delegar en cada tipo de action de alguna manera
    if (action->type == ACTION_TYPE_GO) {
        u8 userParam = buffer[0];

        if (userParam == ASCII_n) {
            action->param1 = DIR_N;
        } else if (userParam == ASCII_s) {
            action->param1 = DIR_S;
        } else if (userParam == ASCII_e) {
            action->param1 = DIR_E;
        } else if (userParam == ASCII_o) {
            action->param1 = DIR_O;
        }
    }
}

TAction *sys_action_parse(u8* buffer) {
    u8* paramPtr;
    action.type = ACTION_TYPE_UNKNOWN;
    action.param1 = ACTION_PARAM_UNKNOWN;

    paramPtr = _parseActionType(buffer, &action);
    _parseActionParam(paramPtr, &action);

    return &action;
}
