#include <string.h>
#include <cpctelera.h>
#include <man/msg/msg.h>

u8 msg[MAN_MSG_MSG_SIZE];

u8 man_msg_getLength() {
    u8 count = 0;
    u8 *msg = man_msg_getPtr();
    while ( (*msg) != 0) {
        ++count;
        ++msg;
    }
    return count;
}

u8* man_msg_clear(void) {
    cpct_memset(msg, 0, MAN_MSG_MSG_SIZE);
    return msg;
}

u8* man_msg_getPtr() {
    return msg;
}

u8* man_msg_concat(u8* str) {
    strcat(msg, str);
    return msg;
}