#include <man/history/history.h>

void man_history_init() {
    THistory *history = man_history_getHistoryPtr();

    for(u8 i = 0; i < HISTORY_NUM_LINES; ++i) {
        history->lines[i].pen = 0;
        cpct_memset(history->lines[i].txt, 0, HISTORY_LINE_SIZE);
    }
}