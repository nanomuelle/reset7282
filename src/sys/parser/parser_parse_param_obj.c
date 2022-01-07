#include <sys/parser/parser.h>
#include <sys/str/str.h>

#include <man/objs/objs.h>

#include <sys/debug/debug.h>

void _sys_parser_parseParamObj(u8* userInput, TAction *action) {
    u8 buffer[PARSER_BUFFER_SIZE];
    TObj *obj;

    sys_str_copyNextWord(userInput, buffer);
    obj = man_objs_findByName(buffer);
    if (obj != 0x00) {
        action->param1.obj_param = obj->id;
    } else {
        action->param1.obj_param = OBJ_ID_NULL;
    }
}
