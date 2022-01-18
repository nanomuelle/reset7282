#include <sys/render/render.h>

void sys_render_updatePrompt(TPrompt *prompt) {
    _render_printChar(PROMPT_CHAR, PROMPT_X, PROMPT_Y, PROMPT_CHAR_PEN);       // :
    _render_printMsg(prompt->buffer, PROMPT_X + 3, PROMPT_Y, PROMPT_CHAR_PEN); // user text
    _render_printChar(
        PROMPT_CURSOR_CHAR, 
        PROMPT_X + 3 + prompt->cursor_pos * 2, 
        PROMPT_Y, 
        PROMPT_CHAR_PEN);  // cursor
}

