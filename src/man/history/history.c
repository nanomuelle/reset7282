#include <man/history/history.h>

THistory history;

void man_history_init() {
    for(u8 i = 0; i < HISTORY_NUM_LINES; ++i) {
        history.lines[i].pen = 0;
        cpct_memset(history.lines[i].txt, 0, HISTORY_LINE_SIZE);
    }
}

THistory *man_history_getHistory(void) {
    return &history;
}

void scrollUpLines() {
    const THistoryLine *lineFrom;
    THistoryLine *lineTo;
    for(u8 i = 1; i < HISTORY_NUM_LINES; ++i) {
        lineFrom = &history.lines[i];
        lineTo = &history.lines[i - 1];

        cpct_memcpy(lineTo, lineFrom, sizeof(THistoryLine));
    }
}

void copyTxtToLastLine(const u8* txt, u8 pen) {
    THistoryLine *line = &history.lines[HISTORY_LAST_LINE];
    u8 index = 0;

    line->pen = pen;

    while(txt[index] != 0) {
        line->txt[index] = txt[index];
        ++index;
    }

    while(index < HISTORY_LINE_SIZE - 1) {
        line->txt[index] = ' ';
        ++index;
    }

    line->txt[HISTORY_LINE_SIZE - 1] = 0;
}

void _addLine(const u8* txt, u8 pen) {
    scrollUpLines();
    copyTxtToLastLine(txt, pen);
}

void man_history_addInfo(const u8* txt) {
    _addLine(txt, 1);
}

void man_history_addWarning(const u8* txt) {
    _addLine(txt, 3);
}

void man_history_addError(const u8* txt) {
    _addLine(txt, 2);
}
