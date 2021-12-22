#include <cpctelera.h>
#include <sys/ascii/ascii.h>

u8 sys_str_isEqual(const u8* str1, const u8* str2) {
    u8 *char1 = str1;
    u8 *char2 = str2;

    while (*char1 == *char2) {
        if (*char1 == 0) {
            return 1; // true
        }
        ++char1;
        ++char2;
    }

    return 0; // false
}

u8* sys_str_ignoreWhiteSpaces(u8* str) {
    while(*str == ASCII_SPACE) ++str;
    return str;
}

//
// copy next word in dst buffer ignoring initial whitespaces
//
// INPUTS:
//   src ptr to origin
//   dst ptr to destiny buffer
// OUTPUT:
//   ptr pointing to start of next word
u8* sys_str_copyNextWord(u8* src, u8* dst) {
    src = sys_str_ignoreWhiteSpaces(src);

    // copy until find an space or a null
    while(*src != 0 && *src != ASCII_SPACE) {
        *dst = *src;
        ++dst;
        ++src;
    }
    *dst = 0;

    return src;
}
