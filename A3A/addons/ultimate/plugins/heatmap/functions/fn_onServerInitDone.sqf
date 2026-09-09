#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_onServerInitDone

Description:
    CBA_EVENT_SERVER_INIT_DONE event handler.

Parameters:

Optional:

Returns:
    Nothing

Environment:
    Server, Scheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
TRACE_1(QFUNC(onServerInitDone),_this);

[ADDON_EVENT_SERVER_UPDATE_HEATMAP, LINKFUNC(onUpdateHeatmap)] call FUNCMAIN(addEventHandler);
[CBA_EVENT_SERVER_ENTITY_POSTMORTEM, LINKFUNC(onServerEntityPostMortem)] call FUNCMAIN(addEventHandler);

nil;
