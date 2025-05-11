/* ----------------------------------------------------------------------------
Function: A3A_fnc_importSave

Description:
    Import save game data

Parameters:
    0: _saveData - Save game meta info <HASHMAP>
    1: _variables - Saved values <HASHMAP>

Optional:

Example:

Returns:
    Nothing

Author:
    goreSplatter
---------------------------------------------------------------------------- */
#include "..\..\script_component.hpp"
FIX_LINE_NUMBERS()

if !assert(params[
    ["_saveData", nil, [createHashMap]],
    ["_variables", nil, [createHashMap]]
]) exitWith {};

// Create new campaign ID, avoiding collisions
private _allIDs = call A3A_fnc_collectSaveData apply { _x get "gameID" };
private _newID = str(floor(random(90000) + 10000));
while { _newID in _allIDs } do { _newID = str(floor(random(90000) + 10000)) };

_saveData set["gameID", _newID];
_saveData set["name", format["[IMPORT] %1", _saveData get "name"]];

Info_1("Importing save data with ID %1",_newID);

_variables apply {
    private _key = _x;
    private _value = _y;
    private _nsKey = format["%1%2", _key, _newID];

    Info_2("Importing variable %1=%2",_nsKey,_value);

    missionProfileNamespace setVariable[_nsKey, _value];
};

_saveData apply {
    if (_x isEqualTo "map") then { continue };

    private _key = _x;
    private _value = _y;
    private _nsKey = format["%1%2", _key, _newID];

    Info_2("Importing game setting %1=%2",_nsKey,_value);

    missionProfileNamespace setVariable[_nsKey, _value];
};

private _nsData = missionProfileNamespace getVariable["antistasiUltimate2SavedGames", []];
_nsData pushBack [_newID, _saveData get "map", "Greenfor"];
missionProfileNamespace setVariable["antistasiUltimate2SavedGames", _nsData];

[] spawn A3A_fnc_setupMonitor;

nil;
