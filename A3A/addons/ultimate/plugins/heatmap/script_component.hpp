#define COMPONENT ultimate
#define SUBCOMPONENT addon_heatmap
#include "\x\A3A\addons\core\Includes\script_mod.hpp"
#include "\x\A3A\addons\ultimate\script_macros_oo.hpp"

#define HEATMAP_CLASS DOUBLES(SUBADDON,Heatmap)

// When killing a CAManBase, add heat with radius of this many meters.
#define HEATMAP_CAMANBASE_SIZE 500
// Anything else getting killes should be a vehicle; use sizeOf and multiply by
// this many meters.
#define HEATMAP_SIZEOF_MULTIPLIER 70
// Wait this many seconds before processing heatmap updates, to allow multiple
// kills in quick succession to be processed together.
#define HEATMAP_UPDATE_DELAY 0.25

#define ADDON_EVENT_SERVER_UPDATE_HEATMAP QUOTE(TRIPLES(SUBADDON,event,serverUpdateHeatmap))
