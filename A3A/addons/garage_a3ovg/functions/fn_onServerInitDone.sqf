#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_garage_a3ovg_fnc_onServerInitDone

Description:
    CBA event handler function called when server initialization is complete.

    Called when the event A3A_EVENT_SERVER_INIT_COMPLETE is fired.

Parameters:
    0: _serverID - Savegame server ID <STRING>
    1: _campaignID - Savegame campaign ID <STRING>
    2: _mapName - Savegame map name <STRING>

Optional:

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Debug_2("%1: %2", QFUNC(onServerInitDone), _this);

if !assert(params[
    ["_serverID", nil, ["", false]],
    ["_campaignID", nil, [""]], 
    ["_mapName", nil, [""]]
]) exitWith {};

Info_3("Server init done. serverID: %1, campaignID: %2, mapName: %3", _serverID, _campaignID, _mapName);

[_campaignID] call A3OVG_fnc_setStoragePrefix;

nil;
