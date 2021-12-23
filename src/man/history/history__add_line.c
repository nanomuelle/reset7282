#include <man/history/history.h>

void _scrollUpLines(THistory* history) {
    const THistoryLine *lineFrom;
    THistoryLine *lineTo;
    for(u8 i = 1; i < HISTORY_NUM_LINES; ++i) {
        lineFrom = &(history->lines[i]);
        lineTo = &(history->lines[i - 1]);

        cpct_memcpy(lineTo, lineFrom, sizeof(THistoryLine));
    }
}

void _copyTxtToLastLine(THistory* history, const u8* txt, u8 pen) {
    THistoryLine *line = &(history->lines[HISTORY_LAST_LINE]);
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

void _history_addLine(THistory* history, const u8* txt, u8 pen) {
    _scrollUpLines(history);
    _copyTxtToLastLine(history, txt, pen);
}