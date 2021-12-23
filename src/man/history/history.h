#ifndef RESET_MAN_HISTORY
#define RESET_MAN_HISTORY

#include <cpctelera.h>

#define HISTORY_NUM_LINES 5
#define HISTORY_LAST_LINE (HISTORY_NUM_LINES - 1)
#define HISTORY_LINE_SIZE 40

#define MAN_HISTORY_PEN_USER_INPUT  1
#define MAN_HISTORY_PEN_ERROR       2
#define MAN_HISTORY_PEN_RESPONSE    3

typedef struct {
    u8 pen;
    u8 txt[HISTORY_LINE_SIZE];
} THistoryLine;

typedef struct {
    THistoryLine lines[HISTORY_NUM_LINES];
} THistory;

// PRIVATE
extern void _history_addLine(THistory *history, const u8* txt, u8 pen);

// PUBLIC
extern void man_history_init(void);
extern THistory* man_history_getHistoryPtr(void);
extern void man_history_addError(const u8* txt);
extern void man_history_addUserInput(const u8* txt);
extern void man_history_addResponse(const u8* txt);

#endif