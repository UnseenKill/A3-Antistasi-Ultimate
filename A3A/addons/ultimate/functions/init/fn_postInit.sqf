#include "..\..\script_component.hpp"

["isNotDeadPlayer", {
    params["_unit"];
    alive _unit;
}] call A3U_fnc_addInteractionCondition;

["isNotDeadTarget", {
    params["","_target"];
    alive _target;
}] call A3U_fnc_addInteractionCondition;

["isNotInVehiclePlayer", {
    params["_unit"];
    isNull objectParent _unit;
}] call A3U_fnc_addInteractionCondition;

["isNotOutOfRange", {
    params["_unit","_target"];
    _unit distance _target < 10;
}] call A3U_fnc_addInteractionCondition;

Info("A3U object definition is now sealed");
GVAR(objectRegistry) = compileFinal GVAR(objectRegistry);
