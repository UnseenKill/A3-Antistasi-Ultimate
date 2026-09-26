#include "..\..\script_component.hpp"

call A3U_fnc_settings;

GVAR(interactionConditions) = createHashMap;

Info("A3U object definition registry is open for business");
GVAR(objectRegistry) = createHashMap;
