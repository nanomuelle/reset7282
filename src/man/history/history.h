#ifndef RESET_MAN_HISTORY
#define RESET_MAN_HISTORY

#include <cpctelera.h>

#define HISTORY_NUM_LINES 5
#define HISTORY_LAST_LINE (HISTORY_NUM_LINES - 1)
#define HISTORY_LINE_SIZE 40

typedef struct {
    u8 pen;
    u8 txt[HISTORY_LINE_SIZE];
} THistoryLine;

typedef struct {
    THistoryLine lines[HISTORY_NUM_LINES];
} THistory;

extern void man_history_init(void);
extern THistory *man_history_getHistory(void);
extern void man_history_addError(const u8* txt);
extern void man_history_addWarning(const u8* txt);
extern void man_history_addInfo(const u8* txt);

#endif