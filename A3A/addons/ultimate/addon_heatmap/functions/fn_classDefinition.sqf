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
    ["#type", QUOTE(HEATMAP_CLASS)],
    ["#flags", ["sealed"]],

    // #region Properties
    // <ARRAY> - of width, height
    ["_dimensions", nil],
    // <ARRAY> - One-dimensional array of heatmap values, length is width*height
    ["_heatmap", nil],
    // <NUMBER> - Map scale; create cells this many meters wide and high
    ["_scale", nil],
    // <BOOL> - Whether to show empty cells (cells with heat value of 0)
    ["_showEmpty", false],
    // <ARRAY> - of <ARRAY> color, <STRING> colorStr, <ARRAY> triangleVertices
    ["_vertices", nil],
    // #endregion

    // #region(collapsed) Methods
    /**
     * #create(Number mapScale) -> Heatmap
     *
     * Constructor method for heatmap object.
     */
    METHOD_DEFINE_NAME(#create,CTOR),

    /**
     * addHeatSpot(Array cellPosition, Array radii, Number intensity) -> Nothing
     *
     * Add heat value to cell position with fall-off based on distance from center.
     */
    METHOD_DEFINE(addHeatSpot),

    /**
    * blobToEllipse(Array cells) -> Array
    *
    * Convert blob of cells to ellipse parameters for drawing.
    */
    METHOD_DEFINE(blobToEllipse),

    /**
     * calcTriangles([Number minX[, Number maxX[, Number minY[, Number maxY]]]]) -> Nothing
     *
     * Calculate triangle vertices, color shading for selected heatmap cells
     * or entire map.
     */
    METHOD_DEFINE(calcTriangles),

    /**
     * cellToPosition(Array cellPosition) -> Array
     *
     * Convert local cell position to world position.
     */
    METHOD_DEFINE(cellToPosition),

    /**
     * findHeatBlobs(Number threshold[, Boolean diagonalNeighbors = true]) -> Array
     *
     * Find contiguous areas of heat values above threshold and return array of
     * cells, boundaries.
     */
    METHOD_DEFINE(findHeatBlobs),

    /**
     * getColors() -> Array
     *
     * Get the color array for the heatmap.
     */
    METHOD_DEFINE(getColors),

    /**
     * getHeat(Array cellPosition[, Number radius]) -> Number
     *
     * Get heat value at cell position.
     *
     * Argument is local cell position. To convert world position to local cell
     * position, use `positionToCell` method. Optional radius argument gets heat
     * value in radius around cell position.
     */
    METHOD_DEFINE(getHeat),

    /**
     * getValue(Array cellPosition) -> Number
     *
     * Internal: get heat value at cell position.
     */
    METHOD_DEFINE(getValue),

    /**
     * getVertex(Array cellPosition) -> Array|Nothing
     *
     * Get vertex information for cell position as <ARRAY> of color, colorStr,
     * triangleVertices. Returns `nil` if cell position is out of bounds or not
     * initialized.
     */
    METHOD_DEFINE(getVertex),

    /**
     * initializeHeatmap() -> Nothing
     *
     * Initialize heatmap array based on dimensions and scale properties.
     */
    METHOD_DEFINE(initializeHeatmap),

    /**
     * paint() -> Nothing
     *
     * Paint the heatmap on the map.
     */
    METHOD_DEFINE(paint),

    /**
    * positionToCell(Array worldPosition) -> Array
    *
    * Convert world position to local cell position.
    */
    METHOD_DEFINE(positionToCell)
    // #endregion
];
