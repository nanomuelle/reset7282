#include <man/history/history.h>
#include <man/msg/msg.h>

void man_history_addTaggedResponse(const u8* txt) {
    THistory *history = man_history_getHistoryPtr();
    _history_addLine(history, txt, MAN_HISTORY_PEN_RESPONSE);
}