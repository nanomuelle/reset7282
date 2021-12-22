#ifndef RESET_MAN_ROOMS
#define RESET_MAN_ROOMS

#include <cpctelera.h>

#define ROOMS_MAX_ROOMS 20
#define NO_EXIT 0xFF

typedef enum {
    ROOM_ID_INITIAL,        // 0
    ROOM_ID_ASEO_1,         // 1
    ROOM_ID_PASILLO_1,      // 2
    ROOM_ID_PASILLO_2,      // 3
    ROOM_ID_DORMITORIO_1    // 4
} TRoomIdEnum;

typedef enum {
    DIR_N = 0,
    DIR_S,
    DIR_E,
    DIR_O
} TRoomDirectionsEnum;

typedef struct {
    u8 direction[4];
} TRoomOuts;

typedef struct {
    const TRoomIdEnum id;
    const u8* name;
    const u8* txt;
    const TRoomOuts outs;
} TRoom;

// PRIVATE
extern TRoom* _currentRoom;
extern TRoom _rooms[ROOMS_MAX_ROOMS];

// PUBLIC
extern void   man_rooms_init          (void);
extern TRoom* man_rooms_getRoomsPtr   (void);
extern TRoom* man_rooms_getCurrentRoom(void);
extern TRoom* man_rooms_setCurrentRoom(TRoomIdEnum);

#endif