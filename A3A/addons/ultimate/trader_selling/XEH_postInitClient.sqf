#include "script_component.hpp"

// TODO: CBA settings
GVAR(playKaching) = false;
GVAR(sellDelay) = 0.125;
GVAR(sellForbidden) = false;
GVAR(sellPriceMultiplier) = 0.75;
// </ TODO: CBA settings>

[{ call FUNC(onGetItemPrice) }] call FUNCMAIN(traderSellingAppraiseItem);

nil;
