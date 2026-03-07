#include "..\..\script_component.hpp"
FIX_LINE_NUMBERS()
/* ----------------------------------------------------------------------------
Function: A3A_fnc_addTeardownActions

Description:
    Add player actions for teardown mode to player.

Parameters:

Optional:

Returns:
    Nothing

Environment:
    Client, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
if (!hasInterface) exitWith {};
if !assert(!isNull player) exitWith {};

// Build mode user actions
player addAction[
    localize "STR_A3A_base_teardownMode_ON",
    { (_this select 1) setVariable[QGVAR(isTeardownActive), true]; [CBA_EVENT_CLIENT_TEARDOWN_MODE_CHANGED, [_this select 1, true]] call FUNCMAIN(triggerLocalEvent) },
    [],
    1.6,
    false,
    false,
    "",
    QUOTE(!([_this] call FUNCMAIN(isTeardownEnabled)) && {isNull objectParent _this} && {[player] call FUNCMAIN(isEngineer)} && {_this inArea QQUOTE(Synd_HQ)})
];

player addAction[
    localize "STR_A3A_base_teardownMode_OFF",
    { (_this select 1) setVariable[QGVAR(isTeardownActive), false]; [CBA_EVENT_CLIENT_TEARDOWN_MODE_CHANGED, [_this select 1, false]] call FUNCMAIN(triggerLocalEvent) },
    [],
    1.6,
    false,
    false,
    "",
    QUOTE(([_this] call FUNCMAIN(isTeardownEnabled)) && {isNull objectParent _this} && {_this inArea QQUOTE(Synd_HQ)})
];

nil;
