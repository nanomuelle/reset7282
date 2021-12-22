#ifndef RESET_MAN_MSG
#define RESET_MAN_MSG
    #include <cpctelera.h>

    #define MAN_MSG_MSG_SIZE 40

    extern u8* man_msg_clear(void);
    extern u8* man_msg_getPtr(void);
    extern u8* man_msg_concat(u8* str);
#endif