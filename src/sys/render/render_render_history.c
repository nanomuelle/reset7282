#include <sys/render/render.h>
#include <man/history/history.h>

void _render_updateHistory(THistory *history) {
    u8 x = 0;
    u8 y = 130;

    for(u8 i=0; i < HISTORY_NUM_LINES; i++) {
        _render_printMsg(history->lines[i].txt, x, y, history->lines[i].pen);
        y += 10;
    }
}