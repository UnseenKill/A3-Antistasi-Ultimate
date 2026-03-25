#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_classDefinition

Description:
    Deliver heatmap hashmap object definition.

Parameters:

Optional:

Returns:
    <HASHMAP>

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
TRACE_1(QFUNC(classDefinition),_this);

createHashMapFromArray[
    ["#type", HEATMAP_CLASS],
    ["#flags", ["sealed"]]
];
