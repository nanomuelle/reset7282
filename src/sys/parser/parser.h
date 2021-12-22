#ifndef RESET_SYS_PARSER
#define RESET_SYS_PARSER

#include <cpctelera.h>

#define PARSER_BUFFER_SIZE 40

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

// PRIVATE
extern void _sys_parser_parseParamGo(u8* userInput, TAction *action);
extern void _sys_parser_parseParamTurnOn(u8* userInput, TAction *action);

// PUBLIC
extern void sys_parser_init(void);
extern TAction* sys_parser_parseAction(u8 *);
extern const u8* sys_parser_getActionName(TAction *);

#endif