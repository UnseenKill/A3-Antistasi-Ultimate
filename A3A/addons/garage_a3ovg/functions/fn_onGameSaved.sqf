#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_garage_a3ovg_fnc_onGameSaved

Description:
    CBA event handler function called when a game is saved.

    Called when the event CBA_EVENT_SERVER_GAME_SAVED is fired.

Parameters:

Optional:

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Debug_2("%1: %2",QFUNC(onGameSaved),_this);

Info("Saving A3OVG garage data.");

[] call A3OVG_fnc_commitChanges;

nil;
