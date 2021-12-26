#include <man/objs/objs.h>
#include <sys/str/str.h>

TObj *man_objs_findByName(const u8* objName) {
    TObj *obj = man_objs_getPtr();

    for(u8 i = 0; i < MAN_OBJS_SIZE; i++) {
        if (sys_str_isEqual(objName, obj->name)) {
            return obj;
        }
        ++obj;
    }

    return 0; // null ptr
}