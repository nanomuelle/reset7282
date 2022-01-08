#ifndef RESET_MAN_ROOMS
#define RESET_MAN_ROOMS

#include <global/reset_types.h>

#define ROOMS_MAX_ROOMS 20
#define NO_EXIT 0xFF

typedef enum RoomIdEnum {
    ROOM_ID_DORMITORIO_1,   // 0
    ROOM_ID_INVENTARIO,     // 1
    ROOM_ID_ASEO_1,         // 2
    ROOM_ID_PASILLO_1,      // 3
    ROOM_ID_PASILLO_2,      // 4
    ROOM_ID_PONG,           // 5
    ROOM_ID_DORMITORIO_2,   // 6
    ROOM_ID_DORMITORIO_3,   // 7
    ROOM_ID_ASEO_2,         // 8
    ROOM_ID_BREAKOUT,       // 9
    ROOM_ID_SALON,          // 10
    ROOM_ID_TERRAZA,        // 11
    ROOM_ID_INVADERS,       // 12
    ROOM_ID_ENTRADA,        // 13
    ROOM_ID_COCINA,         // 14
    ROOM_ID_ALMACEN,        // 15
    ROOM_ID_PACMAN,         // 16
    ROOM_ID_FROGGER,        // 17

    ROOM_ID_EVERYWHERE = 0xff
} TRoomIdEnum;

typedef enum RoomOutEnum {
    OUT_N = 0,
    OUT_S,
    OUT_E,
    OUT_O
} TRoomOutsEnum;

typedef struct RoomOutsStruct {
    TRoomOutsEnum direction[4];
} TRoomOuts;

typedef void (*TGameFn)(void);

#define ROOM_STATE_DEFAULT  ( 0b00000000 )  // state
#define ROOM_STATE_EXPLORED ( 0b00000001 )  // explored room
#define ROOM_STATE_DARK     ( 0b00000010 )  // dark room

typedef struct RoomStruct {
    const TRoomIdEnum id;       // id
    const u8* name;             // nombre
    const u8* txt;              // descripcion
    const u8* txtDark;          // descripcion sin luz
    const TRoomOuts outs;       // salidas
    u8    state;                // state of the room, bit masked
    const TGameHandlers *gameHandlers; // game handlers
} TRoom;

// PRIVATE
extern TRoom* _lastRoom;
extern TRoom* _currentRoom;
extern TRoom _rooms[ROOMS_MAX_ROOMS];

// PUBLIC
extern void   man_rooms_init          (void);
extern TRoom* man_rooms_getRoomsPtr   (void);
extern TRoom* man_rooms_getCurrentRoom(void);
extern TRoom* man_rooms_getLastRoom   (void);
extern TRoom* man_rooms_setCurrentRoom(TRoomIdEnum id);
extern TRoom* man_rooms_getRoom       (TRoomIdEnum id);
extern u8     man_rooms_isExplored    (TRoom* room);
extern u8     man_rooms_isDark        (TRoom* room);
extern void   man_rooms_setExplored   (TRoom* room);
extern void   man_rooms_switchDark    (TRoom* room);

#endif