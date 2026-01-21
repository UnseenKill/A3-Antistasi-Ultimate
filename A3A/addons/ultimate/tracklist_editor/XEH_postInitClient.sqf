#include "script_component.hpp"

TRACE_1(QFUNC(postInitClient),_this);

GVAR(lastTracks) = [];
GVAR(tracks) = nil;
GVAR(waitScript) = nil;

[CBA_EVENT_CLIENT_PLAYER_LOAD, {
    TRACE_1(QFUNC(preInitClient_OnLoad),_this);
    if assert(params[["_saveData", nil, [createHashMap]]]) then {
        GVAR(tracks) = _saveData get QGVAR(tracks);
        [] call FUNC(verifyLoadedTracks);
    };
}] call CBA_fnc_addEventHandler;

[CBA_EVENT_CLIENT_PLAYER_SAVE, {
    TRACE_1(QFUNC(preInitClient_OnSave),_this);
    if assert(params[["_saveData", nil, [createHashMap]]]) then {
        if (GVAR(tracks) isEqualType createHashMap) then {
            _saveData set[QGVAR(tracks), +GVAR(tracks)];
        };
    };
}] call CBA_fnc_addEventHandler;

nil;
