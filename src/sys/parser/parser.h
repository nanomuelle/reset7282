#ifndef RESET_SYS_PARSER
#define RESET_SYS_PARSER

#include <cpctelera.h>
#include <man/objs/objs.h>

#define PARSER_BUFFER_SIZE 40

typedef enum {
    ACTION_TYPE_EXAMINE = 0,
    ACTION_TYPE_GO,
    ACTION_TYPE_INVENTORY,
    ACTION_TYPE_SEARCH,
    ACTION_TYPE_TAKE,
    ACTION_TYPE_TURN_OFF,
    ACTION_TYPE_TURN_ON,
    ACTION_TYPE_UNKNOWN,
    ACTION_TYPE_USE
} TActionType;

typedef enum {
    ACTION_PARAM_UNKNOWN = 0xff
} TParamUnknownEnum;

typedef enum ParamGoEnum {
    ACTION_PARAM_GO_N,
    ACTION_PARAM_GO_S,
    ACTION_PARAM_GO_E,
    ACTION_PARAM_GO_O,
} TParamGoEnum;

typedef union {
    TParamGoEnum go_param;
    TObjEnum obj_param;
    TParamUnknownEnum unknown_param;
} TParam;

typedef struct ActionStruct {
    TActionType type;
    TParam param1;
} TAction;

typedef struct {
    u8* txt;
    TAction action;
} TUserInputToActionMap;

// PRIVATE
extern void _sys_parser_parseParamGo    (u8* userInput, TAction *action);
extern void _sys_parser_parseParamObj   (u8* userInput, TAction *action);

// PUBLIC
extern void sys_parser_init(void);
extern TAction* sys_parser_parseAction(u8 *);

#endif