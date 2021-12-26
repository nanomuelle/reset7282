#include <man/objs/objs.h>

// const u8* OBJ_NAME_RAQUETA = "raqueta";

const TObj _initial_objs[MAN_OBJS_SIZE] = {
    { OBJ_ID_LIGHT  , "luz"    , ROOM_ID_INITIAL     , OBJ_ATTR_CAN_USE  },
    { OBJ_ID_RAQUETA, "raqueta", ROOM_ID_DORMITORIO_1, OBJ_ATTR_CAN_TAKE },
    { OBJ_ID_CONSOLA, "consola", ROOM_ID_DORMITORIO_1, OBJ_ATTR_CAN_USE  },
    { OBJ_ID_NULL   , "null 2" , 0xff                , 0x00 },
    { OBJ_ID_NULL   , "null 3" , 0xff                , 0x00 },
    { OBJ_ID_NULL   , "null 4" , 0xff                , 0x00 },
    { OBJ_ID_NULL   , "null 5" , 0xff                , 0x00 },
    { OBJ_ID_NULL   , "null 6" , 0xff                , 0x00 },
    { OBJ_ID_NULL   , "null 7" , 0xff                , 0x00 },
    { OBJ_ID_NULL   , "null 8" , 0xff                , 0x00 }
};

void man_objs_init(void) {
    cpct_memcpy(_objs, _initial_objs, MAN_OBJS_SIZE * sizeof(TObj));
}