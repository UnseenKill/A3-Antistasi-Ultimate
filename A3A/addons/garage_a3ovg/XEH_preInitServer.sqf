#include "script_component.hpp"

[A3A_EVENT_SERVER_INIT_COMPLETE, { call FUNC(onServerInitDone) }] call CBA_fnc_addEventHandler;

nil;