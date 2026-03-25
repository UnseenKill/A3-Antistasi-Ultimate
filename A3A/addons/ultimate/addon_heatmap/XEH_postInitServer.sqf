#include "script_component.hpp"

[CBA_EVENT_SERVER_STARTUP, { call FUNC(onServerStartup) }] call FUNCMAIN(addEventHandler);

GVAR(heatMaps) = createHashMap;

nil;
