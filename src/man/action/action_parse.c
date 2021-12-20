#include <string.h>
#include <cpctelera.h>
#include <man/action/action.h>
#include <man/prompt/prompt.h>

typedef struct {
    u8* txt;
    ActionTypeEnum type;
} TActionUserInputToActionTypeMap;

#define ACTION_USERINPUT_TO_TYPE_SIZE 7

const TActionUserInputToActionTypeMap userInputToActionTypeMap[ACTION_USERINPUT_TO_TYPE_SIZE] = {
    { "ir", ACTION_GO },
    { "n", ACTION_GO },
    { "s", ACTION_GO },
    { "e", ACTION_GO },
    { "o", ACTION_GO },
    { "buscar", ACTION_SEARCH },
    { "explorar", ACTION_SEARCH },
};

u8 isEqualString(const u8* str1, const u8* str2) {
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

ActionTypeEnum findActionType(u8* userInput) {
    u8 buffer[PROMPT_BUFFER_SIZE];
    u8* bufferPtr = buffer;

    // ignore initial whitespaces
    u8* userInputPtr = userInput;
    while(*userInputPtr == ' ') ++userInputPtr;

    // copy until find an space or a null
    while(*userInputPtr != 0 && *userInputPtr != ' ') {
        *bufferPtr = *userInputPtr;
        ++userInputPtr;
        ++bufferPtr;
    }
    *bufferPtr = 0;

    for (u8 i = 0; i < ACTION_USERINPUT_TO_TYPE_SIZE; i++) {
        TActionUserInputToActionTypeMap *itemMap = &userInputToActionTypeMap[i];
        if (isEqualString(itemMap->txt, buffer)) {
            return itemMap->type;
        }
    }

    return ACTION_UNKNOWN;
}

void man_action_parse(u8* buffer) {
    TAction* currentAction = man_action_getCurrentAction();
    u8 param1 = DIR_UNKNOWN;
    u8 userInput = buffer[0];

    currentAction->type = findActionType(buffer);

    // ACTION_GO ?
    if (userInput == 'n') {
        param1 = DIR_N;
    } else if (userInput == 's') {
        param1 = DIR_S;
    } else if (userInput == 'e') {
        param1 = DIR_E;
    } else if (userInput == 'o') {
        param1 = DIR_O;
    } else {
        // TODO
        // marcar la accion con un error de parametro desconocido en vez 
        //  de cambiar a accion desconocida con idea de dar al usuario
        //  info de que el parametro es lo que falta o falla
        // currentAction->type = ACTION_UNKNOWN;
        param1 = DIR_UNKNOWN;
        // return;
    }

    currentAction->param1 = param1;
}
