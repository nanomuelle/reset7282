#ifndef RESET_SYS_ACTION
#define RESET_SYS_ACTION

#include <cpctelera.h>

typedef enum {
    ACTION_TYPE_GO = 0,
    ACTION_TYPE_SEARCH,
    ACTION_TYPE_TURN_ON,
    ACTION_TYPE_UNKNOWN
} TActionType;

typedef enum {
    ACTION_PARAM_UNKNOWN = 0xff
} TParamUnknownEnum;

typedef enum {
    ACTION_PARAM_GO_N,
    ACTION_PARAM_GO_S,
    ACTION_PARAM_GO_E,
    ACTION_PARAM_GO_O,
    ACTION_PARAM_GO_UNKNOWN
} TParamGoEnum;

typedef enum {
    ACTION_PARAM_SEARCH_UNKNOWN
} TParamSearchEnum;

typedef enum {
    ACTION_PARAM_TURN_ON_LIGHT,
    ACTION_PARAM_TURN_ON_UNKNOWN
} TParamTurnOnEnum;

typedef union {
    TParamUnknownEnum unknown_param;
    TParamGoEnum go_param;
    TParamSearchEnum search_param;
    TParamTurnOnEnum turn_on_param;
} TParam;

typedef struct {
    TActionType type;
    TParam param1;
} TAction;

typedef struct {
    u8* txt;
    TAction action;
} TUserInputToActionMap;

extern void sys_action_init(void);
extern TAction* sys_action_parse(u8 *);
extern const u8* sys_action_getActionName(TAction *);

#endif