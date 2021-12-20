#ifndef RESET_MAN_ACTION
#define RESET_MAN_ACTION

#include <cpctelera.h>
#include <man/rooms/rooms.h>

typedef enum {
    ACTION_GO = 0,
    ACTION_SEARCH,
    ACTION_UNKNOWN,
    ACTION_NULL = 0xFF
} ActionTypeEnum;

typedef struct {
    ActionTypeEnum type;
    u8 param1;
} TAction;

extern void man_action_init(void);
extern TAction* man_action_getCurrentAction(void);
extern void man_action_parse(u8 *);
extern const u8* man_action_getActionName(TAction *);
extern void man_action_execute(TAction *, TRoom *);
extern void man_action_runner_go(TAction *, TRoom *);
extern void man_action_runner_search(TAction *, TRoom *);
extern void man_action_runner_unknown(TAction *, TRoom *);

#endif