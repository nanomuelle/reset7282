#include <man/objs/objs.h>

const TObj _initial_objs[MAN_OBJS_SIZE] = {
    { OBJ_ID_RAQUETA, "raqueta", ROOM_ID_DORMITORIO_1 },
    { OBJ_ID_CONSOLA, "consola", ROOM_ID_DORMITORIO_1 },
    { OBJ_ID_NULL, "null 1", 0xff },
    { OBJ_ID_NULL, "null 2", 0xff },
    { OBJ_ID_NULL, "null 3", 0xff },
    { OBJ_ID_NULL, "null 4", 0xff },
    { OBJ_ID_NULL, "null 5", 0xff },
    { OBJ_ID_NULL, "null 6", 0xff },
    { OBJ_ID_NULL, "null 7", 0xff },
    { OBJ_ID_NULL, "null 8", 0xff }
};

void man_objs_init(void) {
    cpct_memcpy(_objs, _initial_objs, MAN_OBJS_SIZE * sizeof(TObj));
}