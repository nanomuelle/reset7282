#ifndef RESET_MAN_PROMPT
#define RESET_MAN_PROMPT

#include<cpctelera.h>

#define PROMPT_BUFFER_SIZE 38 // bytes
#define PROMPT_BUFFER_NUM_TYPABLE_CHARS (PROMPT_BUFFER_SIZE - 1)
// #define CHAR_SPACING 2 // BYTES

typedef struct {
    char    buffer[PROMPT_BUFFER_SIZE];
    u8      cursor_pos;
} TPrompt;

extern void man_prompt_init(void);
extern void man_prompt_reset(void);
extern void man_prompt_typeChar(char);
extern void man_prompt_delChar(void);
extern TPrompt* man_prompt_getPrompt(void);

#endif