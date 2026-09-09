#include "script_component.hpp"

[CBA_EVENT_SERVER_STARTUP, LINKFUNC(onServerStartup)] call FUNCMAIN(addEventHandler);

GVAR(heatMaps) = createHashMap;

nil;
