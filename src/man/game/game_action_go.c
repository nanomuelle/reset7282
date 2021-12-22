#include <cpctelera.h>
#include <sys/action/action.h>
#include <man/rooms/rooms.h>

#include <sys/debug/debug.h>

void _game_action_go(TAction* action, TRoom* room) {    
    TRoomDirectionsEnum dir = action->param1;

    if (dir == DIR_UNKNOWN) {
        return;
    }

    {
        u8 roomIndex = room->outs.direction[dir];
        //     if (roomIndex == NO_EXIT) {
        //         return;
        //     }
        
        man_rooms_setCurrentRoom(roomIndex);
    }

    // // TODO: deberiamos crear un man_game_setNextRoom
    // //  en vez de acceder directamente a otro manager
    // //  para delegar en game la logica??
}