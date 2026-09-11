#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_calculateHeatIntensity

Description:
    Calculates heat increase for killing an entity, based on its type and size.

Parameters:
    0: _entityOrClassname - The entity or classname to calculate heat for <OBJECT,STRING>

Optional:

Example:
    (begin example)
    ["B_Soldier_F"] call FUNC(calculateHeatIntensity);
    (end example)

Returns:
    <NUMBER> Calculated intensity

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Trace_1(QFUNC(calculateHeatIntensity),_this);

if !assert(params[
    ["_entityOrClassname", nil, [objNull, ""]]
]) exitWith {0};

private _config = if (_entityOrClassname isEqualType objNull) then {
    configOf _entityOrClassname;
} else {
    configFile >> "CfgVehicles" >> typeOf _entityOrClassname;
};

private _cost = getNumber(_config >> "cost");

_cost = _cost / (1e+7);

Trace_2(QFUNC(calculateHeatIntensity),_entityOrClassname,_cost);

_cost max 0.0125;
