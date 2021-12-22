#ifndef RESET_SYS_ACTION
#define RESET_SYS_ACTION

#include <cpctelera.h>

#define ACTION_NULL_PARAM 0xFF


typedef enum {
    ACTION_TYPE_GO = 0,
    ACTION_TYPE_SEARCH,
    ACTION_TYPE_UNKNOWN,
    ACTION_TYPE_NULL = 0xFF
} TActionType;

typedef struct {
    TActionType type;
    u8 param1;
} TAction;

typedef struct {
    u8* txt;
    TAction action;
} TUserInputToActionMap;

extern void sys_action_init(void);
extern TAction* sys_action_parse(u8 *);
extern const u8* sys_action_getActionName(TAction *);

#endif