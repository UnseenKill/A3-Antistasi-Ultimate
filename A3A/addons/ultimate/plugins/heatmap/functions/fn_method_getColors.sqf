#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_getColors

Description:
    Get heatmap color RGBA array used for color shading.

Parameters:

Optional:

Returns:
    <ARRAY> - of RGBA color arrays

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(getColors);

[
    [0, 0, 0.6, 0],
    [0, 0, 0.6, 0.75],
    [1, 0, 0, 0.75],
    [1, 0.9, 0.6, 1]
];
