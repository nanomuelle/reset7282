#include <man/game/game.h>

#include <sys/render/render.h>
#include <sys/input/input.h>

#include <man/rooms/rooms.h>
#include <man/prompt/prompt.h>
#include <man/action/action.h>
#include <man/history/history.h>

void man_game_init(void) {
    cpct_disableFirmware();

    man_rooms_init();
    man_prompt_init();
    man_action_init();
    man_history_init();

    sys_render_init();
    sys_input_init();
}
