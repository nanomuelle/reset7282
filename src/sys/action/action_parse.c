#include <string.h>
#include <cpctelera.h>

#include <man/prompt/prompt.h>
#include <man/rooms/rooms.h>

#include <sys/action/action.h>
#include <sys/ascii/ascii.h>

#include <sys/debug/debug.h>

#define ACTION_USERINPUT_TO_TYPE_SIZE 7

TAction action;

const TActionUserInputToActionTypeMap userInputToActionTypeMap[ACTION_USERINPUT_TO_TYPE_SIZE] = {
    { "ir", ACTION_TYPE_GO },
    { "n", ACTION_TYPE_GO },
    { "s", ACTION_TYPE_GO },
    { "e", ACTION_TYPE_GO },
    { "o", ACTION_TYPE_GO },
    { "buscar", ACTION_TYPE_SEARCH },
    { "explorar", ACTION_TYPE_SEARCH },
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

u8 _copyNextWord(u8* src, u8* dst) {
    u8* dstPtr = dst;

    // copy until find an space or a null
    while(*src != 0 && *src != ASCII_SPACE) {
        *dstPtr = *src;
        ++dstPtr;
        ++src;
    }
    *dstPtr = 0;

    return dstPtr - dst;
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
    u8* bufferPtr = buffer;
    u8* userInputPtr = userInput;

    // ignore initial whitespaces
    userInputPtr = _ignoreWhiteSpaces(userInputPtr);

    // copy until find an space or a null
    userInputPtr += _copyNextWord(userInputPtr, buffer);

    for (u8 i = 0; i < ACTION_USERINPUT_TO_TYPE_SIZE; i++) {
        TActionUserInputToActionTypeMap *itemMap = &userInputToActionTypeMap[i];
        if (_isEqualString(itemMap->txt, buffer)) {
            action->type = itemMap->type;
            break;
        }
    }

    ++userInputPtr;

    sys_debug_info("_parseType", 0, 190);
    sys_debug_waitKey();
    sys_debug_info(userInputPtr, 0, 190);
    sys_debug_waitKey();

    return userInputPtr;
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
    u8* bufferPtr = buffer;
    u8* userInputPtr = userInput;

    action->param1 = ACTION_NULL_PARAM;

    // ignore initial whitespaces
    _ignoreWhiteSpaces(userInputPtr);

    // copy until find an space or a null
    _copyNextWord(userInputPtr, buffer);

    sys_debug_info("_parseParam", 0, 190);
    sys_debug_waitKey();
    sys_debug_info(userInput, 0, 190);
    sys_debug_waitKey();

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
        } else {
            // TODO
            // marcar la accion con un error de parametro desconocido en vez 
            //  de cambiar a accion desconocida con idea de dar al usuario
            //  info de que el parametro es lo que falta o falla
            // currentAction->type = ACTION_UNKNOWN;
            action->param1 = DIR_UNKNOWN;
            // return;
        }
        return;
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
