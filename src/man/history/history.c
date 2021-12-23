#include <man/history/history.h>

THistory history;

THistory *man_history_getHistoryPtr(void) {
    return &history;
}