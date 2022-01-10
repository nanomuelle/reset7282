#include <man/objs/objs.h>
#include <assets/obj_paddel.h>
#include <assets/obj_consola.h>
#include <assets/obj_deportivas.h>

// const u8* OBJ_NAME_RAQUETA = "raqueta";

const TObj _initial_objs[MAN_OBJS_SIZE] = {
    { OBJ_ID_LIGHT,
        "luz",
        "el interruptor de la luz",
        ROOM_ID_EVERYWHERE,
        OBJ_ATTR_CAN_USE,
        0x0000
    },
    { OBJ_ID_RAQUETA,
        "raqueta",
        "es rara, parece un palo rectangular",
        ROOM_ID_DORMITORIO_1,
        OBJ_ATTR_CAN_TAKE,
        g_tile_obj_paddel
    },
    { OBJ_ID_CONSOLA,
        "consola",
        "consola Magnavox Odyssey, un clasico",
        ROOM_ID_DORMITORIO_1,
        OBJ_ATTR_CAN_USE,
        g_tile_obj_consola
    },
    { OBJ_ID_DEPORTIVAS,
        "deportivas",
        "unas Nike Cortez de 1972",
        ROOM_ID_PONG,
        OBJ_ATTR_CAN_TAKE,
        g_tile_obj_deportivas,
    },
    { OBJ_ID_NULL   , "null 5" , "null", 0xff                , 0x00, 0x0000 },
    { OBJ_ID_NULL   , "null 6" , "null", 0xff                , 0x00, 0x0000 },
    { OBJ_ID_NULL   , "null 7" , "null", 0xff                , 0x00, 0x0000 },
    { OBJ_ID_NULL   , "null 8" , "null", 0xff                , 0x00, 0x0000 },
    { OBJ_ID_NULL   , "null 9" , "null", 0xff                , 0x00, 0x0000 },
    { OBJ_ID_NULL   , "null 10" , "null", 0xff                , 0x00, 0x0000 }
};

void man_objs_init(void) {
    cpct_memcpy(_objs, _initial_objs, MAN_OBJS_SIZE * sizeof(TObj));
}