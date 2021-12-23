#include <man/history/history.h>
#include <man/msg/msg.h>

void man_history_addResponse(const u8* txt) {
    THistory *history = man_history_getHistoryPtr();

    u8* msg = man_msg_clear();
    man_msg_concat("-> ");
    man_msg_concat(txt);
    _history_addLine(history, msg, MAN_HISTORY_PEN_RESPONSE);
}