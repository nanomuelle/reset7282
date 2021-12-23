#include <sys/parser/parser.h>
#include <sys/str/str.h>

#include <man/objs/objs.h>

void _sys_parser_parseParamTake(u8* userInput, TAction *action) {
    u8 buffer[PARSER_BUFFER_SIZE];

    sys_str_copyNextWord(userInput, buffer);

    if (sys_str_isEqual("raqueta", buffer)) {
        action->param1.take_param = ACTION_PARAM_TAKE_RAQUETA;
    } else {
        action->param1.take_param = ACTION_PARAM_TAKE_UNKNOWN;
    }
}
