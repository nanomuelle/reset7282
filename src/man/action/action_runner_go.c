#include <cpctelera.h>
#include <man/action/action.h>
#include <man/rooms/rooms.h>

#include <sys/debug/debug.h>

void man_action_runner_go(TAction* action, TRoom* room) {
    sys_debug_infoString("man_action_runner_go (any key to continue)", 0, 50);
    sys_debug_waitKey();
    
    // TRoomDirectionsEnum direction = action->param1;

    // if (direction == DIR_UNKNOWN) {
    //     return;
    // }

    // {
    //     u8 roomIndex = room->outs.direction[direction];
    //     if (roomIndex == NO_EXIT) {
    //         return;
    //     }

    //     man_rooms_setCurrentRoom(roomIndex);
    // }

    // // TODO: deberiamos crear un man_game_setNextRoom
    // //  en vez de acceder directamente a otro manager
    // //  para delegar en game la logica??
}