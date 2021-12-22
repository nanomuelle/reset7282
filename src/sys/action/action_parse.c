#include <string.h>
#include <cpctelera.h>

#include <man/prompt/prompt.h>
#include <man/rooms/rooms.h>

#include <sys/action/action.h>
#include <sys/ascii/ascii.h>

#include <sys/debug/debug.h>

#define ACTION_USERINPUT_TO_TYPE_SIZE 7

TAction action;

const TUserInputToActionMap userInputToActionMap[ACTION_USERINPUT_TO_TYPE_SIZE] = {
    { "ir",         { ACTION_TYPE_GO    , DIR_UNKNOWN       } },
    { "n",          { ACTION_TYPE_GO    , DIR_N             } },
    { "s",          { ACTION_TYPE_GO    , DIR_S             } },
    { "e",          { ACTION_TYPE_GO    , DIR_E             } },
    { "o",          { ACTION_TYPE_GO    , DIR_O             } },
    { "buscar",     { ACTION_TYPE_SEARCH, ACTION_NULL_PARAM } },
    { "explorar",   { ACTION_TYPE_SEARCH, ACTION_NULL_PARAM } },
    NULL
};

u8 _isEqualString(const u8* str1, const u8* str2) {
    u8 *char1 = str1;
    u8 *char2 = str2;

    while (*char1 == *char2) {
        if (*char1 == 0) {
            return 1; // true
        }
        ++char1;
        ++char2;
    }

    return 0; // false
}

u8* _ignoreWhiteSpaces(u8* str) {
    while(*str == ASCII_SPACE) ++str;
    return str;
}

//
// copy next word in dst buffer ignoring initial whitespaces
//
// INPUTS:
//   src ptr to origin
//   dst ptr to destiny buffer
// OUTPUT:
//   ptr pointing to start of next word
u8* _copyNextWord(u8* src, u8* dst) {
    src = _ignoreWhiteSpaces(src);

    // copy until find an space or a null
    while(*src != 0 && *src != ASCII_SPACE) {
        *dst = *src;
        ++dst;
        ++src;
    }
    *dst = 0;

    return src;
}

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

    userInput = _copyNextWord(userInput, buffer);

    for (u8 i = 0; i < ACTION_USERINPUT_TO_TYPE_SIZE; i++) {
        TUserInputToActionMap *itemMap = &userInputToActionMap[i];
        if (_isEqualString(itemMap->txt, buffer)) {
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
    _copyNextWord(userInput, buffer);

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
    action.param1 = ACTION_NULL_PARAM;

    paramPtr = _parseActionType(buffer, &action);
    _parseActionParam(paramPtr, &action);

    return &action;
}
