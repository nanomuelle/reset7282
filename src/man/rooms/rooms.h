#ifndef RESET_MAN_ROOMS
#define RESET_MAN_ROOMS

#include <cpctelera.h>

#define ROOMS_MAX_ROOMS 20
#define NO_EXIT 0xFF

typedef enum RoomIdEnum {
    ROOM_ID_INITIAL,        // 0
    ROOM_ID_INVENTARIO,     // 1
    ROOM_ID_ASEO_1,         // 2
    ROOM_ID_PASILLO_1,      // 3
    ROOM_ID_PASILLO_2,      // 4
    ROOM_ID_DORMITORIO_1,   // 5
    ROOM_ID_PONG            // 6
} TRoomIdEnum;

typedef enum RoomOutEnum {
    OUT_N = 0,
    OUT_S,
    OUT_E,
    OUT_O
} TRoomOutsEnum;

typedef enum RoomExploredEnum {
    NOT_EXPLORED = 0,
    EXPLORED
} TExploredEnum;

typedef struct RoomOutsStruct {
    TRoomOutsEnum direction[4];
} TRoomOuts;

typedef void (*TGameFn)(void);
typedef struct RoomStruct {
    const TRoomIdEnum id;   // id
    const u8* name;         // nombre
    const u8* txt;          // descripcion
    const TRoomOuts outs;   // salidas
    TExploredEnum explored; // indicador de habitacion explorada
    // const TGameFn renderer; // ptr to renderer fn
    // const TGameFn inputer;  // ptr to input fn
    // const TGameFn updater;  // ptr to updater fn
} TRoom;

// PRIVATE
extern TRoom* _currentRoom;
extern TRoom _rooms[ROOMS_MAX_ROOMS];

// PUBLIC
extern void   man_rooms_init          (void);
extern TRoom* man_rooms_getRoomsPtr   (void);
extern TRoom* man_rooms_getCurrentRoom(void);
extern TRoom* man_rooms_setCurrentRoom(TRoomIdEnum id);
extern TRoom* man_rooms_getRoom       (TRoomIdEnum id);

#endif