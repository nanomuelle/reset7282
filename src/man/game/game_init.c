#include <man/game/game.h>

#include <man/rooms/rooms.h>
#include <man/prompt/prompt.h>
#include <man/history/history.h>
#include <man/objs/objs.h>

#include <sys/render/render.h>
#include <sys/input/input.h>
#include <sys/parser/parser.h>

void man_game_init(void) {
    cpct_disableFirmware();

    man_rooms_init();
    man_objs_init();
    man_prompt_init();
    man_history_init();

    sys_parser_init();
    sys_input_init();
    sys_render_init();
}
