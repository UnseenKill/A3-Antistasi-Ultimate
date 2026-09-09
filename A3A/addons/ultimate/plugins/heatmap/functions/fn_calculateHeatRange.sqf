#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_calculateHeatRange

Description:
    Calculates heat spacial spread for killed entity, based on its type and size.

Parameters:
    0: _entityOrClassname - The entity or classname to calculate heat for <OBJECT,STRING>

Optional:

Example:
    (begin example)
    ["B_Soldier_F"] call FUNC(calculateHeatRange);
    (end example)

Returns:
    <ARRAY> Calculated heat range in local format (not world coordinates)

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Trace_1(QFUNC(calculateHeatRange),_this);

if !assert(params[
    ["_entityOrClassname", nil, [objNull, ""]]
]) exitWith {0};

private _class = if (_entityOrClassname isEqualType "") then {
    _entityOrClassname;
} else {
    typeOf _entityOrClassname;
};

private _size = if (_class isKindOf "CAManBase") then {
    HEATMAP_CAMANBASE_SIZE
} else {
    HEATMAP_SIZEOF_MULTIPLIER * (sizeOf _class)
};

Trace_2(QFUNC(calculateHeatRange),_entityOrClassname,_size);

[_size, _size];
