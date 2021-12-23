#include <man/objs/objs.h>

TObj *man_objs_getObj(TObjEnum id) {
    TObj *src = man_objs_getPtr();

    while (src->id != id) {
        ++src;
    }

    return src;
}