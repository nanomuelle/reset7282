#include <sys/parser/parser.h>
#include <sys/ascii/ascii.h>

void _sys_parser_parseParamGo(u8* userInput, TAction *action) {
    u8 userParam = userInput[0];

    if (userParam == ASCII_n) {
        action->param1.go_param = ACTION_PARAM_GO_N;
    } else if (userParam == ASCII_s) {
        action->param1.go_param = ACTION_PARAM_GO_S;
    } else if (userParam == ASCII_e) {
        action->param1.go_param = ACTION_PARAM_GO_E;
    } else if (userParam == ASCII_o) {
        action->param1.go_param = ACTION_PARAM_GO_O;
    } else {
        action->param1.go_param = ACTION_PARAM_UNKNOWN;
    }
}
