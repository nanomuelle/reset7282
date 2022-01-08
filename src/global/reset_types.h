#ifndef RESET_TYPES
#define RESET_TYPES

#include <cpctelera.h>

typedef void (*TGameHandlerCallback)(void);

typedef struct GameHandlersStruct {
    TGameHandlerCallback readInput;
    TGameHandlerCallback update;
    TGameHandlerCallback render;
} TGameHandlers;

#endif