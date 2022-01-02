#include <man/history/history.h>
#include <man/msg/msg.h>

void man_history_addMsg(THistoryMsg *msg) {
    switch (msg->type) {
        case HISTORY_TYPE_ERROR:
            man_history_addError(msg->txt);
        break;

        case HISTORY_TYPE_USER_INPUT:
            man_history_addUserInput(msg->txt);
        break;

        case HISTORY_TYPE_TAGGED_RESPONSE:
            man_history_addTaggedResponse(msg->txt);
        break;

        default:
            man_history_addResponse(msg->txt);
        break;
    }
}