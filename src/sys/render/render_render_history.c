#include <sys/render/render.h>
#include <man/history/history.h>

void sys_render_renderHistory(THistory *history) {
    u8 x = 0;
    u8 y = 130;

    for(u8 i=0; i < HISTORY_NUM_LINES; i++) {
        printMsg(history->lines[i].txt, x, y, history->lines[i].pen);
        y += 10;
    }
}