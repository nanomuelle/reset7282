#include <string.h>
#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/rooms/rooms.h>

#include <sys/action/action.h>

#include <sys/debug/debug.h>

void _game_action_go(TAction* action, TRoom* room) {    
    TRoomDirectionsEnum dir = action->param1;
    u8 roomIndex;
    u8* dirAsString[] = {" n", " s", " e", " o"};
    u8 msg[40] = "";

    strcat(msg, sys_action_getActionName(action));

    if (dir == DIR_UNKNOWN) {
        man_history_addInfo("ir ?");
        man_history_addWarning(" ->ir hacia donde?");
        return;
    }

    strcat(msg, dirAsString[action->param1]);
    man_history_addInfo(msg);

    roomIndex = room->outs.direction[dir];
    if (roomIndex == NO_EXIT) {        
        man_history_addWarning(" -> por ahi no hay salida");
        return;
    }

    {
        TRoom *room = man_rooms_setCurrentRoom(roomIndex);

        cpct_memset(msg, 0, 40);
        strcat(msg, " -> ");
        strcat(msg, room->name);
        man_history_addWarning(msg);
    }


    // // TODO: deberiamos crear un man_game_setNextRoom
    // //  en vez de acceder directamente a otro manager
    // //  para delegar en game la logica??
}