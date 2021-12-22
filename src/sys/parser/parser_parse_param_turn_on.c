#include <sys/parser/parser.h>
#include <sys/str/str.h>

#include <sys/debug/debug.h>

void _sys_parser_parseParamTurnOn(u8* userInput, TAction *action) {
    u8 buffer[PARSER_BUFFER_SIZE];

    sys_str_copyNextWord(userInput, buffer);

    if (sys_str_isEqual("luz", buffer)) {
        action->param1.turn_on_param = ACTION_PARAM_TURN_ON_LIGHT;
    } else {
        action->param1.turn_on_param = ACTION_PARAM_TURN_ON_UNKNOWN;
    }
}
