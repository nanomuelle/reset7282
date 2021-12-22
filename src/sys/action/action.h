#ifndef RESET_SYS_ACTION
#define RESET_SYS_ACTION

#include <cpctelera.h>

typedef enum {
    ACTION_TYPE_GO = 0,
    ACTION_TYPE_SEARCH,
    ACTION_TYPE_TURN_ON,
    ACTION_TYPE_UNKNOWN,
    ACTION_TYPE_NULL = 0xFF
} TActionType;

typedef enum {
    ACTION_PARAM_DIR_N = 0,
    ACTION_PARAM_DIR_S,
    ACTION_PARAM_DIR_E,
    ACTION_PARAM_DIR_O,

    ACTION_PARAM_TURN_ON_LIGHT,

    ACTION_PARAM_UNKNOWN
} TParamEnum;

typedef struct {
    TActionType type;
    TParamEnum param1;
} TAction;

typedef struct {
    u8* txt;
    TAction action;
} TUserInputToActionMap;

extern void sys_action_init(void);
extern TAction* sys_action_parse(u8 *);
extern const u8* sys_action_getActionName(TAction *);

#endif