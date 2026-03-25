#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_fnc_postmortem

Description:
    Handles the despawn and cleanup of dead units

Parameters:
    0: _victim - The dead unit <OBJECT>

Optional:
    1: _killer - The unit responsible for the death <OBJECT>

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Trace_1(QFUNCMAIN(postmortem),_this);

if !assert(isServer) exitWith { Error("Function can only be called on the server.") };
if !assert(params[
    ["_victim", nil, [objNull]]
]) exitWith {};
if (isNull _victim) exitWith {};

[CBA_EVENT_SERVER_ENTITY_POSTMORTEM, _this] call FUNCMAIN(triggerLocalEvent);

[_victim] call FUNCMAIN(despawnQueueEntity);

nil;
