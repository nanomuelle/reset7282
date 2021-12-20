#include <man/game/game.h>
#include <man/prompt/prompt.h>
#include <man/action/action.h>
#include <sys/input/input.h>

void man_game_input(void) {
    u8 key = sys_input_waitKey();
    cpct_disableFirmware();

    if (key == KEY_DEL) {
        man_prompt_delChar();
        return;
    }

    if (key == KEY_ENTER) {
        TPrompt *prompt = man_prompt_getPrompt();
        man_action_parse(prompt->buffer);
        return;
    }

    man_prompt_typeChar(key);
}
