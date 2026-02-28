#include "..\BuildObjectsList.hpp"
class australia {
    population[] = {
        {"Adelaide", 1492},
        {"Alice Springs", 468},
        {"Bannister", 200},
        {"Bathurst", 154},
        {"Beermullah", 361},
        {"Brisbane", 1243},
        {"Broken Hill", 385},
        {"Cairns", 816},
        {"Coober Pedy", 227},
        {"Darwin", 791},
        {"Davenport", 11},
        {"Eden", 243},
        {"Hobart", 80},
        {"Launceston", 180},
        {"Melbourne", 1392},
        {"Mildura", 375},
        {"Mount Isa", 58},
        {"Novac", 30},
        {"Perth", 973},
        {"Port Lincoln", 81},
        {"Rockhampton", 1219},
        {"Shantytown", 59},
        {"Smithton", 41},
        {"Sydney", 3132},
        {"Tailem bend", 124},
        {"Weipa", 199},
        {"Willcania", 638},
        {"Yirrkala", 7}
    };
    disabledTowns[] = {
        // Australia uses locations as map region markers, so the list of
        // disabled towns isn't really towns... Also note the EXORBITANT
        // multitude of fucking ways to name a location name class. We have:
        // Location_Name, location_Name, location_name, and, of course
        // Location_name. This HAS to be deliberate.
        "nsw","NT","qld","sa","Tasmania","vic","West_australia", // let that the fuck sink in
        "army_base1","Cape_Melville","cape_peron","flinders_island","garden_island","groote_Eylandt","Kangaroo_island",
        "King_island","moreton_island","phillip_island","pinegap","rottnest_island","stuart_hwy","tiwi_island","Toowoomba"
    };
    antennas[] = {
        {17287.2,21902.2,0},    // Outpost 9
        {25354.3,12176,0},      // Outpost 12
        {33818.2,15752.7,0},    // Outpost 17
        {17639,34250,0},        // Milbase NE of Darwin
        {31913.5,24880.6,0},    // Milbase 5
        {19878.4,24456.6,0}     // Pine Gap
    };
    antennasBlacklistIndex[] = {};
    banks[] = {
        {5427,19265,0} // Beermullah
    };
    garrison[] = {
        {},
        {
            "airport_1","factory_3","milbase_1","outpost_2","outpost_14","outpost_15","resource_9","seaport_5",
            "control_31","control_32","control_33","control_35","control_37","control_38","control_39","control_40","control_41","control_89","control_91","control_111"
        },
        {},
        {
            "control_31","control_32","control_33","control_35","control_37","control_38","control_39","control_40","control_41","control_89","control_91","control_111"
        }
    };
    fuelStationTypes[] = {
        "Land_FuelStation_Feed_F","Land_fs_feed_F","Land_FuelStation_01_pump_malevil_F","Land_FuelStation_01_pump_F","Land_FuelStation_02_pump_F","Land_FuelStation_03_pump_F"
    };
    milAdministrations[] = {
        {25408.1,12648,0},          // Adelaide
        {21994.5,25648.9,0},        // Alice
        {27641.1,16947.1,0},        // Broken Hill
        {16337.4,33631.3,0.367885}, // Darwin
        {33177.7,3988.62,0},        // Launceston
        {30974.2,10370.9,0},        // Melbourne
        {5624,18613,0},             // Perth NE
        {4640.42,17897,0},          // Perth SW
        {36432.4,13065.8,0}         // Sydney
    };
    climate = "arid";
    buildObjects[] = {
        BUILDABLES_HISTORIC,
        BUILDABLES_UNIVERSAL,
        BUILDABLES_MODERN_GREEN,
        BUILDABLES_MODERN_SAND,
        BUILDABLES_ARID,
        BUILDABLES_TROPIC
    };
};
