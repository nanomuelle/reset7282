#include <cpctelera.h>
#include <man/prompt/prompt.h>

TPrompt prompt;

TPrompt *man_prompt_getPrompt() {
    return &prompt;
}

void man_prompt_init() {
    man_prompt_reset();
}

void man_prompt_reset(void) {
    cpct_memset(prompt.buffer, ' ', PROMPT_BUFFER_SIZE);
    prompt.buffer[PROMPT_BUFFER_SIZE - 1] = 0;
    prompt.cursor_pos = 0;
}

void man_prompt_typeChar(char c) {
    if (prompt.cursor_pos == PROMPT_BUFFER_NUM_TYPABLE_CHARS) {
        return;
    }

    prompt.buffer[prompt.cursor_pos] = c;
    ++prompt.cursor_pos;
}

void man_prompt_delChar(void) {
    if (prompt.cursor_pos == 0) {
        return;
    }

    --prompt.cursor_pos;
    prompt.buffer[prompt.cursor_pos] = ' ';
}