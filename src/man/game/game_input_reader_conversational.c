#include <man/game/game.h>
#include <man/prompt/prompt.h>
#include <sys/input/input.h>
#include <sys/render/render.h>

void man_game_inputReaderConversational(void) {
    u8 key = 0x00;
    TPrompt* prompt = man_prompt_getPrompt();

    while (key != KEY_ENTER) {
        sys_render_updatePrompt(prompt);

        key = sys_input_waitKey();
        cpct_disableFirmware();

        if (key != KEY_ENTER) {
            man_prompt_typeChar(key);
        }
    }
}
