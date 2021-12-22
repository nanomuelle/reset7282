#ifndef RESET_SYS_STR
#define RESET_SYS_STR
    #include <cpctelera.h>

    extern u8 sys_str_isEqual(u8* str1, u8*str2);
    extern u8* sys_str_ignoreWhiteSpaces(u8* str);
    extern u8* sys_str_copyNextWord(u8* src, u8* dst);
#endif