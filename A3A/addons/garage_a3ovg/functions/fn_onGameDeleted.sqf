#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_garage_a3ovg_fnc_onGameDeleted

Description:
    CBA event handler function called when a saved game is deleted.

    Called when the event CBA_EVENT_SERVER_GAME_DELETED is fired.

Parameters:
    0: _serverID - Old server ID <STRING|BOOL>
    1: _campaignID - Game campaign ID <STRING>
    2: _mapName - Game map name <STRING>

Optional:

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Debug_2("%1: %2",QFUNC(onGameDeleted),_this);

if !assert(params[
    ["_serverID", nil, ["", false]],
    ["_campaignID", nil, [""]], 
    ["_mapName", nil, [""]]
]) exitWith {};
if !assert(_serverID isEqualType false) exitWith { Error_1("%1: old-style save system unsupported by A3OVG.",QFUNC(onGameDeleted)) };

Info_3("Deleting saved game serverID: %1, campaignID: %2, mapName: %3", _serverID, _campaignID, _mapName);

[_campaignID] call A3OVG_fnc_purgePrefix;

nil;
