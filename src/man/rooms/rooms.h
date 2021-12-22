#ifndef RESET_MAN_ROOMS
#define RESET_MAN_ROOMS

#include <cpctelera.h>

#define ROOMS_MAX_ROOMS 4
#define NO_EXIT 0xFF

#define ROOM_INITIAL      0
#define ROOM_ASEO_1       1
#define ROOM_PASILLO_1    2
#define ROOM_PASILLO_2    3
#define ROOM_DORMITORIO_1 4

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
    const u8* name;
    const u8* txt;
    const TRoomOuts outs;
} TRoom;

extern void   man_rooms_init          (void);
extern TRoom* man_rooms_getCurrentRoom(void);
extern TRoom* man_rooms_setCurrentRoom(u8);

#endif