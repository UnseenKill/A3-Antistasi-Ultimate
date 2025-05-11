/* ----------------------------------------------------------------------------
Function: A3A_fnc_exportSave

Description:
    Export save game data to hashmap.

Parameters:
    0: _saveID - Unique save game id <STRING>
    1: _waitUUID - A UUID that this function's caller expects to be set in `missionNamespace` <STRING>

Optional:

Example:
    (begin example)
    // Client side
    private _uuid = [] call CBA_fnc_createUUID;
    ["12345", _uuid] remoteExec ["A3A_fnc_exportSave", 2];
    waitUntil { missionNamespace getVariable[_uuid, false] isNotEqualTo false };
    private _saveData = missionNamespace getVariable _uuid;
    (end example)

Returns:
    Nothing

Author:
    goreSplatter
---------------------------------------------------------------------------- */
#include "..\..\script_component.hpp"
FIX_LINE_NUMBERS()

params [
    ["_saveID", "", [""]],
    ["_waitUUID", "", [""]]
];

if !assert(_saveID isNotEqualTo "") exitWith {};
if !assert(_waitUUID isNotEqualTo "") exitWith {};

if (isServer && hasInterface) then {
    uiSleep 3;
};

private _len = count _saveID;
private _data = createHashMap;

allVariables missionProfileNamespace select {
    _x select[count _x - _len] isEqualTo _saveID;
} apply {
    private _key = _x;
    private _normalized = _key select[0, count _key - _len];
    private _value = missionProfileNamespace getVariable _key;

    //diag_log format["%1=%2", _normalized, _value];

    _data set[_normalized, _value];
};

missionNamespace setVariable[_waitUUID, _data, true];

// Clean up after a couple of minutes as not to pollute the namespace; payloads may be huge
[{
    params["_uuid"];
    missionNamespace setVariable[_uuid, nil, true];
}, [_waitUUID], 120] call CBA_fnc_waitAndExecute;

nil;
