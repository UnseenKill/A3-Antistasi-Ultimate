class CBA_Extended_EventHandlers_base;

class CfgVehicles {
    class Item_Base_F;
    class Thing;

    class Item_TFAR_SCR536: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "SCR-536";
        author = AUTHOR;
        vehicleClass = "Items";
        class TransportItems {
            class _xx_TFAR_SCR536 {
                name="TFAR_SCR536";
                count=1;
            };
        };
    };

    class Prop_TFAR_SCR536: Thing {
        destrType = "DestructNo";
        scope = 2;
        scopeCurator = 2;
        model = QPATHTOFOLDER(patches\scr536);
        displayName = "SCR-536 Handie Talkie";
        // editorCategory = "";
        // vehicleClass="";
    };

    class Helipad_base_F;

    class A3AU_RebHelipad_base_F: Helipad_base_F {
        accuracy = 1000;
        author = AUTHOR;
        authors[] = {"wersal454", "UnseenKill"};

        EGVAR(core,restorePriority) = 95;
        EGVAR(core,onBuildingCompleted) = QUOTE(call A3A_fnc_handlerTerrainManipulator);
        EGVAR(core,onBuildingLoaded) = QUOTE(call A3A_fnc_handlerTerrainManipulator);

        class EGVAR(core,Properties) {
            actions[] = {"terrainCleaner", "terrainSmootherExperimental"};
            cleanRadius = 30;
            cleanTerrainTypes[] = {};
            smoothRadius[] = {40, 70}; // <main zone>,<smoothing zone>
        };
    };

    class A3AU_RebHelipad_Circle_F: A3AU_RebHelipad_base_F {
        scope = 2;
        scopeCurator = 2;

        displayName = $STR_A3_CFGVEHICLES_LAND_HELIPADCIRCLE_F0;
        editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_HelipadCircle_F.jpg";
        model = "\A3\Structures_F\Mil\Helipads\HelipadCircle_F.p3d";
    };

    class A3AU_RebHelipad_Square_F: A3AU_RebHelipad_base_F {
        scope = 2;
        scopeCurator = 2;

        displayName = $STR_A3_CFGVEHICLES_LAND_HELIPADSQUARE_F0;
        editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_HelipadSquare_F.jpg";
        mapSize = 11.92;
        model = "\A3\Structures_F\Mil\Helipads\HelipadSquare_F.p3d";
        icon = "iconObject_1x1";
    };

    class Land_Shovel_F;
    class Land_Axe_F;

    class A3AU_TerrainSmoother_Base_F: Land_Shovel_F {
        scope = 0; // Hide from editor
        scopeCurator = 0; // Hide from Zeus
        displayName = "Terrain Smoother Base";
        author = AUTHOR;
        authors[] = {"wersal454", "UnseenKill"};
        model = "\A3\Structures_F_Bootcamp\VR\Helpers\VR_3DSelector_01_F.p3d";

        EGVAR(core,restorePriority) = 100;
        EGVAR(core,onBuildingCompleted) = QUOTE(call A3A_fnc_handlerTerrainManipulator);
        EGVAR(core,onBuildingLoaded) = QUOTE(call A3A_fnc_handlerTerrainManipulator);

        class EGVAR(core,Properties) {
            actions[] = {"terrainSmoother", "hideObject"};
            previewShape = "ellipse"; // ellipse or rectangle
            smoothRadius[] = {0, 0}; // <main zone>,<smoothing zone>
        };
    };

    class A3AU_TerrainSmoother_VerySmall_F: A3AU_TerrainSmoother_Base_F {
        scope = 2;
        displayName = "Terrain Smoother (4 m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            previewWidth = 4;
            previewHeight = 4;
            smoothRadius[] = {4, 8};
        };
    };
    class A3AU_TerrainSmoother_Small_F: A3AU_TerrainSmoother_Base_F {
        scope = 2;
        displayName = "Terrain Smoother (8 m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            previewWidth = 8;
            previewHeight = 8;
            smoothRadius[] = {8, 16};
        };
    };
    class A3AU_TerrainSmoother_Medium_F: A3AU_TerrainSmoother_Base_F {
        scope = 2;
        displayName = "Terrain Smoother (15 m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            previewWidth = 15;
            previewHeight = 15;
            smoothRadius[] = {15, 27};
        };
    };
    class A3AU_TerrainSmoother_Large_F: A3AU_TerrainSmoother_Base_F {
        scope = 2;
        displayName = "Terrain Smoother (30 m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            previewWidth = 30;
            previewHeight = 30;
            smoothRadius[] = {30, 42};
        };
    };

    class A3AU_VegetationCleaner_Base_F: Land_Axe_F {
        scope = 0; // Hide from editor
        scopeCurator = 0; // Hide from Zeus
        displayName = "Vegetation Cleaner Base";
        author = AUTHOR;
        authors[] = {"wersal454", "UnseenKill"};
        model = "\A3\Structures_F_Bootcamp\VR\Helpers\VR_3DSelector_01_F.p3d";

        EGVAR(core,restorePriority) = 100;
        EGVAR(core,onBuildingCompleted) = QUOTE(call A3A_fnc_handlerTerrainManipulator);
        EGVAR(core,onBuildingLoaded) = QUOTE(call A3A_fnc_handlerTerrainManipulator);

        class EGVAR(core,Properties) {
            actions[] = {"terrainCleaner", "hideObject"};
            cleanRadius = 0;
            cleanTerrainTypes[] = {"ROCKS", "ROCK", "TREE", "BUSH", "SMALL TREE", "HIDE"};
            previewShape = "ellipse"; // ellipse or rectangle
        };
    };

    class A3AU_VegetationCleaner_VerySmall_F: A3AU_VegetationCleaner_Base_F {
        scope = 2;
        displayName = "Vegetation Cleaner (4 m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            cleanRadius = 4;
            previewWidth = 4;
            previewHeight = 4;
        };
    };
    class A3AU_VegetationCleaner_Small_F: A3AU_VegetationCleaner_Base_F {
        scope = 2;
        displayName = "Vegetation Cleaner (8 m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            cleanRadius = 8;
            previewWidth = 8;
            previewHeight = 8;
        };
    };
    class A3AU_VegetationCleaner_Medium_F: A3AU_VegetationCleaner_Base_F {
        scope = 2;
        displayName = "Vegetation Cleaner (15 m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            cleanRadius = 15;
            previewWidth = 15;
            previewHeight = 15;
        };
    };
    class A3AU_VegetationCleaner_Large_F: A3AU_VegetationCleaner_Base_F {
        scope = 2;
        displayName = "Vegetation Cleaner (30 m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            cleanRadius = 30;
            previewWidth = 30;
            previewHeight = 30;
        };
    };

    class Land_ButaneTorch_F;

    // BB -> base builder
    class GVAR(BB_TerrainObjectHider_Base) : Land_ButaneTorch_F {
        scope = 0; // Hide from editor
        scopeCurator = 0; // Hide from Zeus
        displayName = "Terrain Cleaner Base";
        author = AUTHOR;
        authors[] = {"UnseenKill"};
        model = "\A3\Structures_F_Bootcamp\VR\Helpers\VR_3DSelector_01_F.p3d";

        EGVAR(core,restorePriority) = 90;
        EGVAR(core,onBuildingCompleted) = QUOTE(call A3A_fnc_handlerTerrainManipulator);
        EGVAR(core,onBuildingLoaded) = QUOTE(call A3A_fnc_handlerTerrainManipulator);

        class EGVAR(core,Properties) {
            actions[] = {"terrainCleaner", "hideObject"};
            cleanRadius = 0;
            cleanTerrainTypes[] = {};
            previewShape = "ellipse"; // ellipse or rectangle
        };

        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
    };

    class GVAR(BB_TerrainObjectHider_Circle4x4) : GVAR(BB_TerrainObjectHider_Base) {
        scope = 2;
        displayName = "Terrain Cleaner (4m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            cleanRadius = 4;
            previewWidth = 4;
            previewHeight = 4;
        };
    };

    class GVAR(BB_TerrainObjectHider_Circle8x8) : GVAR(BB_TerrainObjectHider_Base) {
        scope = 2;
        displayName = "Terrain Cleaner (8m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            cleanRadius = 8;
            previewWidth = 8;
            previewHeight = 8;
        };
    };

    class GVAR(BB_TerrainObjectHider_Circle15x15) : GVAR(BB_TerrainObjectHider_Base) {
        scope = 2;
        displayName = "Terrain Cleaner (15m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            cleanRadius = 15;
            previewWidth = 15;
            previewHeight = 15;
        };
    };

    class GVAR(BB_TerrainObjectHider_Circle30x30) : GVAR(BB_TerrainObjectHider_Base) {
        scope = 2;
        displayName = "Terrain Cleaner (30m)";

        class EGVAR(core,Properties): EGVAR(core,Properties) {
            cleanRadius = 30;
            previewWidth = 30;
            previewHeight = 30;
        };
    };

    // Custom classes for Antistasi Units / Vehicles in Eden / Zeus
    class SoldierWB;
    class I_Soldier_base_F : SoldierWB {
        class EventHandlers;
    };
    class A3U_Rebels_Base: I_Soldier_base_F {
        scope = 1;
        scopeCurator = 1;
        scopeArsenal = 1;
        faction = "A3U_Rebels";
        //icon = "";
        //picture = "";
        //role = "";
        //nameSound = "";
        //textSingular = "";
        //textPlural = "";
        uniformClass = "";
        backpack = "";
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
        weapons[] = {"Throw", "Put"};
        respawnWeapons[] = {"Throw", "Put"};
        magazines[] = {};
        respawnMagazines[] = {};
        //genericNames = "";
        //identityTypes[] = {};
        class EventHandlers {
            class ADDON {
                PostInit = QUOTE([ARR_2(_this#0,false)] call A3A_fnc_fiaInit);
                init = QUOTE((_this#0) setVariable[ARR_2(QUOTE(QUOTE(unitType)),getText(configOf(_this#0) >> QQGVAR(unitType)))]);
            };
        };
    };
    class A3U_Rebels_Rifleman: A3U_Rebels_Base {
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "A3U_Militia";
        displayName = "Rebel Rifleman";
        //icon = "";
        //picture = "";
        role = "Rifleman";
        nameSound = "veh_infantry_s";
        textSingular = "infantry";
        textPlural = "infantry";
        GVAR(unitType) = QUOTE(loadouts_reb_militia_Rifleman);
    };
    class A3U_Rebels_SquadLeader : A3U_Rebels_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_SquadLeader'];";
            };
        };
    };
    class A3U_Rebels_staticCrew : A3U_Rebels_Rifleman {
        displayName = "Static Crew";
        role = "Crew";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_staticCrew'];";
            };
        };
    };
    class A3U_Rebels_Medic : A3U_Rebels_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_Medic'];";
            };
        };
    };
    class A3U_Rebels_Engineer : A3U_Rebels_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_Engineer'];";
            };
        };
    };
    class A3U_Rebels_ExplosivesExpert : A3U_Rebels_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_ExplosivesExpert'];";
            };
        };
    };
    class A3U_Rebels_Grenadier : A3U_Rebels_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_Grenadier'];";
            };
        };
    };
    class A3U_Rebels_LAT : A3U_Rebels_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_LAT'];";
            };
        };
    };
    class A3U_Rebels_AT : A3U_Rebels_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_AT'];";
            };
        };
    };
    class A3U_Rebels_AA : A3U_Rebels_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_AA'];";
            };
        };
    };
    class A3U_Rebels_MachineGunner : A3U_Rebels_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_MachineGunner'];";
            };
        };
    };
    class A3U_Rebels_Marksman : A3U_Rebels_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_Marksman'];";
            };
        };
    };
    class A3U_Rebels_Sniper : A3U_Rebels_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_Sniper'];";
            };
        };
    };
    class A3U_Rebels_Unarmed : A3U_Rebels_Rifleman {
        displayName = "Unarmed";
        role = "Unarmed";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_reb_militia_Unarmed'];";
            };
        };
    };

    class B_Soldier_base_F : SoldierWB {
        class EventHandlers;
    };
    class A3U_Occupants_Base : B_Soldier_base_F {
        scope = 1;
        scopeCurator = 1;
        scopeArsenal = 1;
        faction = "A3U_Occupants";
        //icon = "";
        //picture = "";
        //role = "";
        //nameSound = "";
        //textSingular = "";
        //textPlural = "";
        uniformClass = "";
        backpack = "";
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
        weapons[] = {"Throw", "Put"};
        respawnWeapons[] = {"Throw", "Put"};
        magazines[] = {};
        respawnMagazines[] = {};
        //genericNames = "";
        //identityTypes[] = {};
        class EventHandlers {
            class ADDON {
                PostInit = "params ['_unit']; [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_Rifleman: A3U_Occupants_Base {
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "A3U_Militia";
        role = "Rifleman";
        nameSound = "veh_infantry_s";
        textSingular = "infantry";
        textPlural = "infantry";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_Rifleman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_Rifleman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_SquadLeader : A3U_Occupants_Militia_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other'];_unit setVariable ['unitType', 'loadouts_occ_militia_SquadLeader'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_SquadLeader') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_Radioman : A3U_Occupants_Militia_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_Radioman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_Radioman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_Medic : A3U_Occupants_Militia_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_Medic'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_Medic') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_Engineer : A3U_Occupants_Militia_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_Engineer'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_Engineer') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_ExplosivesExpert : A3U_Occupants_Militia_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_ExplosivesExpert'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_ExplosivesExpert') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_Grenadier : A3U_Occupants_Militia_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_Grenadier'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_Grenadier') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_LAT : A3U_Occupants_Militia_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_LAT'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_LAT') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_AT : A3U_Occupants_Militia_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_AT'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_AT') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_AA : A3U_Occupants_Militia_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_AA'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_AA') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_MachineGunner : A3U_Occupants_Militia_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_MachineGunner'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_MachineGunner') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_Marksman : A3U_Occupants_Militia_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_Marksman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_Marksman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_Sniper : A3U_Occupants_Militia_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_Sniper'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_Sniper') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_PatrolSniper : A3U_Occupants_Militia_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_PatrolSniper'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_PatrolSniper') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Militia_PatrolSpotter : A3U_Occupants_Militia_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_militia_PatrolSpotter'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'militia_PatrolSpotter') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Military";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_Rifleman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_Rifleman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_SquadLeader : A3U_Occupants_Military_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_SquadLeader'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_SquadLeader') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_Radioman : A3U_Occupants_Military_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_Radioman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_Radioman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_Medic : A3U_Occupants_Military_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_Medic'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_Medic') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_Engineer : A3U_Occupants_Military_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_Engineer'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_Engineer') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_ExplosivesExpert : A3U_Occupants_Military_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_ExplosivesExpert'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_ExplosivesExpert') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_Grenadier : A3U_Occupants_Military_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_Grenadier'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_Grenadier') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_LAT : A3U_Occupants_Military_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_LAT'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_LAT') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_AT : A3U_Occupants_Military_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_AT'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_AT') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_AA : A3U_Occupants_Military_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_AA'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_AA') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_MachineGunner : A3U_Occupants_Military_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_MachineGunner'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_MachineGunner') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_Marksman : A3U_Occupants_Military_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_Marksman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_Marksman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_Sniper : A3U_Occupants_Military_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_Sniper'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_Sniper') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_PatrolSniper : A3U_Occupants_Military_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_PatrolSniper'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_PatrolSniper') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Military_PatrolSpotter : A3U_Occupants_Military_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'military']; _unit setVariable ['unitType', 'loadouts_occ_military_PatrolSpotter'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'military_PatrolSpotter') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Elite";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_Rifleman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_Rifleman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_SquadLeader : A3U_Occupants_Elite_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_SquadLeader'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_SquadLeader') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_Radioman : A3U_Occupants_Elite_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_Radioman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_Radioman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_Medic : A3U_Occupants_Elite_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_Medic'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_Medic') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_Engineer : A3U_Occupants_Elite_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_Engineer'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_Engineer') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_ExplosivesExpert : A3U_Occupants_Elite_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_ExplosivesExpert'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_ExplosivesExpert') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_Grenadier : A3U_Occupants_Elite_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_Grenadier'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_Grenadier') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_LAT : A3U_Occupants_Elite_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_LAT'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_LAT') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_AT : A3U_Occupants_Elite_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_AT'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_AT') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_AA : A3U_Occupants_Elite_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_AA'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_AA') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_MachineGunner : A3U_Occupants_Elite_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_MachineGunner'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_MachineGunner') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_Marksman : A3U_Occupants_Elite_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_Marksman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_Marksman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_Sniper : A3U_Occupants_Elite_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_Sniper'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_Sniper') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_PatrolSniper : A3U_Occupants_Elite_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_PatrolSniper'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_PatrolSniper') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Elite_PatrolSpotter : A3U_Occupants_Elite_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'elite']; _unit setVariable ['unitType', 'loadouts_occ_elite_PatrolSpotter'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'elite_PatrolSpotter') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_SpecialForces";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_Rifleman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_Rifleman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_SquadLeader : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_SquadLeader'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_SquadLeader') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_Radioman : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_Radioman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_Radioman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_Medic : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_Medic'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_Medic') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_Engineer : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_Engineer'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_Engineer') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_ExplosivesExpert : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_ExplosivesExpert'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_ExplosivesExpert') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_Grenadier : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_Grenadier'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_Grenadier') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_LAT : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_LAT'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_LAT') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_AT : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_AT'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_AT') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_AA : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_AA'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_AA') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_MachineGunner : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_MachineGunner'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_MachineGunner') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_Marksman : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_Marksman'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_Marksman') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_SpecialForces_Sniper : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'SF']; _unit setVariable ['unitType', 'loadouts_occ_sf_Sniper'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'SF_Sniper') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Police_Standard : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Police";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'police']; _unit setVariable ['unitType', 'loadouts_occ_police_Standard'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'police_Standard') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Police_SquadLeader : A3U_Occupants_Police_Standard {
        displayName = "Squad Leader";
        role = "SquadLeader";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'police']; _unit setVariable ['unitType', 'loadouts_occ_police_SquadLeader'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'police_SquadLeader') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Other_Crew : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Other";
        displayName = "Crew";
        role = "Crew";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_other_Crew'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'other_Crew') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Other_Pilot : A3U_Occupants_Other_Crew {
        displayName = "Pilot";
        role = "Pilot";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_other_Pilot'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'other_Pilot') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Other_Official : A3U_Occupants_Other_Crew {
        displayName = "Official";
        role = "Officer";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_other_Official'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'other_Official') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Other_Traitor : A3U_Occupants_Other_Crew {
        displayName = "Traitor";
        role = "Rifleman";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_other_Traitor'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'other_Traitor') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Occupants_Other_Unarmed : A3U_Occupants_Other_Crew {
        displayName = "Unarmed";
        role = "Unarmed";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitPrefix', 'other']; _unit setVariable ['unitType', 'loadouts_occ_other_Unarmed'];";
                PostInit = "params ['_unit']; _unit setUnitLoadout selectRandom (((A3A_faction_occ get 'loadouts') get 'other_Unarmed') select 0); [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };

    class O_Soldier_base_F : SoldierWB {
        class EventHandlers;
    };
    class A3U_Invaders_Base : O_Soldier_base_F {
        scope = 1;
        scopeCurator = 1;
        scopeArsenal = 1;
        displayName = "Invaders Base";
        faction = "A3U_Invaders";
        editorSubcategory = "EdSubcat_Personnel";
        //icon = "";
        //picture = "";
        //role = "";
        //nameSound = "";
        //textSingular = "";
        //textPlural = "";
        uniformClass = "";
        backpack = "";
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
        weapons[] = {"Throw", "Put"};
        respawnWeapons[] = {"Throw", "Put"};
        magazines[] = {};
        respawnMagazines[] = {};
        //genericNames = "";
        //identityTypes[] = {};
        class EventHandlers {
            class ADDON {
                init = "params ['_unit']; [_unit, '', false] call A3A_fnc_NATOinit;";
            };
        };
    };
    class A3U_Invaders_Rifleman: A3U_Invaders_Base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Invader Rifleman";
        role = "Rifleman";
        nameSound = "veh_infantry_s";
        textSingular = "infantry";
        textPlural = "infantry";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_occupants_civilian_Occupant'];";
            };
        };
    };

    class A3U_Rivals_Base : A3U_Invaders_Base {
        displayName = "Rivals Base";
        faction = "A3U_Rivals";
    };
    class A3U_Rivals_Rifleman: A3U_Rivals_Base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Rival Rifleman";
        role = "Rifleman";
        nameSound = "veh_infantry_s";
        textSingular = "infantry";
        textPlural = "infantry";
        class EventHandlers : EventHandlers {
            class ADDON : ADDON {
                init = "params ['_unit']; _unit setVariable ['unitType', 'loadouts_occupants_civilian_Occupant'];";
            };
        };
    };
};

class Extended_InitPost_EventHandlers {
    class A3AU_TerrainSmoother_Base_F {
        class ADDON {
            clientInit = QUOTE(call A3A_fnc_handlerTerrainObjectHiderPostInitClient);
        };
    };

    class A3AU_VegetationCleaner_Base_F {
        class ADDON {
            clientInit = QUOTE(call A3A_fnc_handlerTerrainObjectHiderPostInitClient);
        };
    };

    class GVAR(BB_TerrainObjectHider_Base) {
        class ADDON {
            clientInit = QUOTE(call A3A_fnc_handlerTerrainObjectHiderPostInitClient);
        };
    };
};
