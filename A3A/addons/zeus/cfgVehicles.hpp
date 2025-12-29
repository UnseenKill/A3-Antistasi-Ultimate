class CfgVehicles {
    // Custom classes for Antistasi Units / Vehicles in Eden / Zeus
    class SoldierWB;

    // ------------ Rebels ------------ //
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
        GVAR(unitFaction) = QUOTE(reb);
        class EventHandlers {
            class ADDON {
                PostInit = QUOTE([ARR_4(_this#0,getText(configOf(_this#0) >> QQGVAR(unitFaction)),getText(configOf(_this#0) >> QQGVAR(unitPrefix)),getText(configOf(_this#0) >> QQGVAR(unitType)))] call A3U_fnc_zeus_unitInit);
            };
        };
    };
    class A3U_Rebels_Rifleman: A3U_Rebels_Base {
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "A3U_Militia";
        displayName = "Rifleman";
        //icon = "";
        //picture = "";
        role = "Rifleman";
        nameSound = "veh_infantry_s";
        textSingular = "infantry";
        textPlural = "infantry";
        GVAR(unitPrefix) = QUOTE(militia);
        GVAR(unitType) = QUOTE(loadouts_reb_militia_Rifleman);
    };
    class A3U_Rebels_SquadLeader : A3U_Rebels_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Rebels_staticCrew : A3U_Rebels_Rifleman {
        displayName = "Static Crew";
        role = "Crew";
        GVAR(unitType) = QUOTE(staticCrew);
    };
    class A3U_Rebels_Medic : A3U_Rebels_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Rebels_Engineer : A3U_Rebels_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Rebels_ExplosivesExpert : A3U_Rebels_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Rebels_Grenadier : A3U_Rebels_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Rebels_LAT : A3U_Rebels_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Rebels_AT : A3U_Rebels_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Rebels_AA : A3U_Rebels_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Rebels_MachineGunner : A3U_Rebels_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Rebels_Marksman : A3U_Rebels_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Rebels_Sniper : A3U_Rebels_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Rebels_Unarmed : A3U_Rebels_Rifleman {
        displayName = "Unarmed";
        role = "Unarmed";
        GVAR(unitType) = QUOTE(Unarmed);
    };

    // ---------- Occupants ---------- //
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
        GVAR(unitFaction) = QUOTE(occ);
        class EventHandlers {
            class ADDON {
                PostInit = QUOTE([ARR_4(_this#0,getText(configOf(_this#0) >> QQGVAR(unitFaction)),getText(configOf(_this#0) >> QQGVAR(unitPrefix)),getText(configOf(_this#0) >> QQGVAR(unitType)))] call A3U_fnc_zeus_unitInit);
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
        GVAR(unitPrefix) = QUOTE(militia);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Occupants_Militia_SquadLeader : A3U_Occupants_Militia_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_Militia_Radioman : A3U_Occupants_Militia_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Occupants_Militia_Medic : A3U_Occupants_Militia_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Occupants_Militia_Engineer : A3U_Occupants_Militia_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Occupants_Militia_ExplosivesExpert : A3U_Occupants_Militia_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Occupants_Militia_Grenadier : A3U_Occupants_Militia_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Occupants_Militia_LAT : A3U_Occupants_Militia_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Occupants_Militia_AT : A3U_Occupants_Militia_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Occupants_Militia_AA : A3U_Occupants_Militia_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Occupants_Militia_MachineGunner : A3U_Occupants_Militia_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Occupants_Militia_Marksman : A3U_Occupants_Militia_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Occupants_Militia_Sniper : A3U_Occupants_Militia_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Occupants_Militia_PatrolSniper : A3U_Occupants_Militia_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Occupants_Militia_PatrolSpotter : A3U_Occupants_Militia_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Occupants_Military_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Military";
        GVAR(unitPrefix) = QUOTE(military);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Occupants_Military_SquadLeader : A3U_Occupants_Military_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_Military_Radioman : A3U_Occupants_Military_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Occupants_Military_Medic : A3U_Occupants_Military_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Occupants_Military_Engineer : A3U_Occupants_Military_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Occupants_Military_ExplosivesExpert : A3U_Occupants_Military_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Occupants_Military_Grenadier : A3U_Occupants_Military_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Occupants_Military_LAT : A3U_Occupants_Military_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Occupants_Military_AT : A3U_Occupants_Military_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Occupants_Military_AA : A3U_Occupants_Military_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Occupants_Military_MachineGunner : A3U_Occupants_Military_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Occupants_Military_Marksman : A3U_Occupants_Military_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Occupants_Military_Sniper : A3U_Occupants_Military_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Occupants_Military_PatrolSniper : A3U_Occupants_Military_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Occupants_Military_PatrolSpotter : A3U_Occupants_Military_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Occupants_Elite_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Elite";
        GVAR(unitPrefix) = QUOTE(elite);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Occupants_Elite_SquadLeader : A3U_Occupants_Elite_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_Elite_Radioman : A3U_Occupants_Elite_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Occupants_Elite_Medic : A3U_Occupants_Elite_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Occupants_Elite_Engineer : A3U_Occupants_Elite_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Occupants_Elite_ExplosivesExpert : A3U_Occupants_Elite_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Occupants_Elite_Grenadier : A3U_Occupants_Elite_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Occupants_Elite_LAT : A3U_Occupants_Elite_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Occupants_Elite_AT : A3U_Occupants_Elite_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Occupants_Elite_AA : A3U_Occupants_Elite_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Occupants_Elite_MachineGunner : A3U_Occupants_Elite_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Occupants_Elite_Marksman : A3U_Occupants_Elite_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Occupants_Elite_Sniper : A3U_Occupants_Elite_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Occupants_Elite_PatrolSniper : A3U_Occupants_Elite_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Occupants_Elite_PatrolSpotter : A3U_Occupants_Elite_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Occupants_SpecialForces_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_SpecialForces";
        GVAR(unitPrefix) = QUOTE(SF);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Occupants_SpecialForces_SquadLeader : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_SpecialForces_Radioman : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Occupants_SpecialForces_Medic : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Occupants_SpecialForces_Engineer : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Occupants_SpecialForces_ExplosivesExpert : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Occupants_SpecialForces_Grenadier : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Occupants_SpecialForces_LAT : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Occupants_SpecialForces_AT : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Occupants_SpecialForces_AA : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Occupants_SpecialForces_MachineGunner : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Occupants_SpecialForces_Marksman : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Occupants_SpecialForces_Sniper : A3U_Occupants_SpecialForces_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Occupants_Police_Standard : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Police";
        GVAR(unitPrefix) = QUOTE(police);
        GVAR(unitType) = QUOTE(Standard);
    };
    class A3U_Occupants_Police_SquadLeader : A3U_Occupants_Police_Standard {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_Other_Crew : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Other";
        displayName = "Crew";
        role = "Crew";
        GVAR(unitPrefix) = QUOTE(other);
        GVAR(unitType) = QUOTE(Crew);
    };
    class A3U_Occupants_Other_Pilot : A3U_Occupants_Other_Crew {
        displayName = "Pilot";
        role = "Pilot";
        GVAR(unitType) = QUOTE(Pilot);
    };
    class A3U_Occupants_Other_Official : A3U_Occupants_Other_Crew {
        displayName = "Official";
        role = "Officer";
        GVAR(unitType) = QUOTE(Official);
    };
    class A3U_Occupants_Other_Traitor : A3U_Occupants_Other_Crew {
        displayName = "Traitor";
        role = "Rifleman";
        GVAR(unitType) = QUOTE(Traitor);
    };
    class A3U_Occupants_Other_Unarmed : A3U_Occupants_Other_Crew {
        displayName = "Unarmed";
        role = "Unarmed";
        GVAR(unitType) = QUOTE(Unarmed);
    };

    // ---------- Invaders ---------- //
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
        GVAR(unitFaction) = QUOTE(inv);
        class EventHandlers {
            class ADDON {
                PostInit = QUOTE([ARR_4(_this#0,getText(configOf(_this#0) >> QQGVAR(unitFaction)),getText(configOf(_this#0) >> QQGVAR(unitPrefix)),getText(configOf(_this#0) >> QQGVAR(unitType)))] call A3U_fnc_zeus_unitInit);
            };
        };
    };
    class A3U_Invaders_Militia_Rifleman: A3U_Invaders_Base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Rifleman";
        editorSubcategory = "A3U_Militia";
        role = "Rifleman";
        nameSound = "veh_infantry_s";
        textSingular = "infantry";
        textPlural = "infantry";
        GVAR(unitPrefix) = QUOTE(militia);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Invaders_Militia_SquadLeader : A3U_Invaders_Militia_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Invaders_Militia_Radioman : A3U_Invaders_Militia_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Invaders_Militia_Medic : A3U_Invaders_Militia_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Invaders_Militia_Engineer : A3U_Invaders_Militia_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Invaders_Militia_ExplosivesExpert : A3U_Invaders_Militia_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Invaders_Militia_Grenadier : A3U_Invaders_Militia_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Invaders_Militia_LAT : A3U_Invaders_Militia_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Invaders_Militia_AT : A3U_Invaders_Militia_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Invaders_Militia_AA : A3U_Invaders_Militia_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Invaders_Militia_MachineGunner : A3U_Invaders_Militia_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Invaders_Militia_Marksman : A3U_Invaders_Militia_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Invaders_Militia_Sniper : A3U_Invaders_Militia_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Invaders_Militia_PatrolSniper : A3U_Invaders_Militia_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Invaders_Militia_PatrolSpotter : A3U_Invaders_Militia_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Invaders_Military_Rifleman : A3U_Invaders_Militia_Rifleman {
        editorSubcategory = "A3U_Military";
        GVAR(unitPrefix) = QUOTE(military);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Invaders_Military_SquadLeader : A3U_Invaders_Military_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Invaders_Military_Radioman : A3U_Invaders_Military_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Invaders_Military_Medic : A3U_Invaders_Military_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Invaders_Military_Engineer : A3U_Invaders_Military_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Invaders_Military_ExplosivesExpert : A3U_Invaders_Military_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Invaders_Military_Grenadier : A3U_Invaders_Military_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Invaders_Military_LAT : A3U_Invaders_Military_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Invaders_Military_AT : A3U_Invaders_Military_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Invaders_Military_AA : A3U_Invaders_Military_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Invaders_Military_MachineGunner : A3U_Invaders_Military_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Invaders_Military_Marksman : A3U_Invaders_Military_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Invaders_Military_Sniper : A3U_Invaders_Military_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Invaders_Military_PatrolSniper : A3U_Invaders_Military_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Invaders_Military_PatrolSpotter : A3U_Invaders_Military_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Invaders_Elite_Rifleman : A3U_Invaders_Militia_Rifleman {
        editorSubcategory = "A3U_Elite";
        GVAR(unitPrefix) = QUOTE(elite);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Invaders_Elite_SquadLeader : A3U_Invaders_Elite_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Invaders_Elite_Radioman : A3U_Invaders_Elite_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Invaders_Elite_Medic : A3U_Invaders_Elite_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Invaders_Elite_Engineer : A3U_Invaders_Elite_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Invaders_Elite_ExplosivesExpert : A3U_Invaders_Elite_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Invaders_Elite_Grenadier : A3U_Invaders_Elite_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Invaders_Elite_LAT : A3U_Invaders_Elite_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Invaders_Elite_AT : A3U_Invaders_Elite_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Invaders_Elite_AA : A3U_Invaders_Elite_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Invaders_Elite_MachineGunner : A3U_Invaders_Elite_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Invaders_Elite_Marksman : A3U_Invaders_Elite_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Invaders_Elite_Sniper : A3U_Invaders_Elite_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Invaders_Elite_PatrolSniper : A3U_Invaders_Elite_Rifleman {
        displayName = "Patrol Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Invaders_Elite_PatrolSpotter : A3U_Invaders_Elite_Rifleman {
        displayName = "Patrol Spotter";
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Invaders_SpecialForces_Rifleman : A3U_Invaders_Militia_Rifleman {
        editorSubcategory = "A3U_SpecialForces";
        GVAR(unitPrefix) = QUOTE(SF);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Invaders_SpecialForces_SquadLeader : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Invaders_SpecialForces_Radioman : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Radioman";
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Invaders_SpecialForces_Medic : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Invaders_SpecialForces_Engineer : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Engineer";
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Invaders_SpecialForces_ExplosivesExpert : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Invaders_SpecialForces_Grenadier : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Grenadier";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Invaders_SpecialForces_LAT : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "LAT";
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Invaders_SpecialForces_AT : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Invaders_SpecialForces_AA : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Invaders_SpecialForces_MachineGunner : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Machine Gunner";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Invaders_SpecialForces_Marksman : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Invaders_SpecialForces_Sniper : A3U_Invaders_SpecialForces_Rifleman {
        displayName = "Sniper";
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Invaders_Police_Standard : A3U_Invaders_Militia_Rifleman {
        editorSubcategory = "A3U_Police";
        GVAR(unitPrefix) = QUOTE(police);
        GVAR(unitType) = QUOTE(Standard);
    };
    class A3U_Invaders_Police_SquadLeader : A3U_Invaders_Police_Standard {
        displayName = "Squad Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Invaders_Other_Crew : A3U_Invaders_Militia_Rifleman {
        editorSubcategory = "A3U_Other";
        displayName = "Crew";
        role = "Crew";
        GVAR(unitPrefix) = QUOTE(other);
        GVAR(unitType) = QUOTE(Crew);
    };
    class A3U_Invaders_Other_Pilot : A3U_Invaders_Other_Crew {
        displayName = "Pilot";
        role = "Pilot";
        GVAR(unitType) = QUOTE(Pilot);
    };
    class A3U_Invaders_Other_Official : A3U_Invaders_Other_Crew {
        displayName = "Official";
        role = "Officer";
        GVAR(unitType) = QUOTE(Official);
    };
    class A3U_Invaders_Other_Traitor : A3U_Invaders_Other_Crew {
        displayName = "Traitor";
        role = "Rifleman";
        GVAR(unitType) = QUOTE(Traitor);
    };
    class A3U_Invaders_Other_Unarmed : A3U_Invaders_Other_Crew {
        displayName = "Unarmed";
        role = "Unarmed";
        GVAR(unitType) = QUOTE(Unarmed);
    };

    // ------------ Rivals ------------ //
    class A3U_Rivals_Base : A3U_Invaders_Base {
        displayName = "Rivals Base";
        faction = "A3U_Rivals";
        GVAR(unitFaction) = QUOTE(riv);
        class EventHandlers {
            class ADDON {
                PostInit = QUOTE([ARR_4(_this#0,getText(configOf(_this#0) >> QQGVAR(unitFaction)),getText(configOf(_this#0) >> QQGVAR(unitPrefix)),getText(configOf(_this#0) >> QQGVAR(unitType)))] call A3U_fnc_zeus_unitInit);
            };
        };
    };
    class A3U_Rivals_Partisan: A3U_Rivals_Base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Partisan";
        editorSubcategory = "A3U_Militia";
        role = "Rifleman";
        nameSound = "veh_infantry_s";
        textSingular = "infantry";
        textPlural = "infantry";
        GVAR(unitPrefix) = QUOTE(militia);
        GVAR(unitType) = QUOTE(Partisan);
    };
    class A3U_Rivals_Militia_Mercenary : A3U_Rivals_Partisan {
        displayName = "Mercenary";
        GVAR(unitType) = QUOTE(Mercenary);
    };
    class A3U_Rivals_Militia_Minuteman : A3U_Rivals_Partisan {
        displayName = "Minuteman";
        GVAR(unitType) = QUOTE(Minuteman);
    };
    class A3U_Rivals_Militia_Enforcer : A3U_Rivals_Partisan {
        displayName = "Enforcer";
        GVAR(unitType) = QUOTE(Enforcer);
    };
    class A3U_Rivals_Militia_CellLeader : A3U_Rivals_Partisan {
        displayName = "Cell Leader";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(CellLeader);
    };
    class A3U_Rivals_Militia_Commander : A3U_Rivals_Partisan {
        displayName = "Commander";
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(Commander);
    };
    class A3U_Rivals_Militia_Medic : A3U_Rivals_Partisan {
        displayName = "Medic";
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Rivals_Militia_ExplosivesExpert : A3U_Rivals_Partisan {
        displayName = "Explosives Expert";
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Rivals_Militia_Saboteur : A3U_Rivals_Partisan {
        displayName = "Saboteur";
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Saboteur);
    };
    class A3U_Rivals_Militia_SpecialistAT : A3U_Rivals_Partisan {
        displayName = "AT Specialist";
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(SpecialistAT);
    };
    class A3U_Rivals_Militia_SpecialistAA : A3U_Rivals_Partisan {
        displayName = "AA Specialist";
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(SpecialistAA);
    };
    class A3U_Rivals_Militia_Oppressor : A3U_Rivals_Partisan {
        displayName = "Oppressor";
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(Oppressor);
    };
    class A3U_Rivals_Militia_Sharpshooter : A3U_Rivals_Partisan {
        displayName = "Marksman";
        role = "Marksman";
        GVAR(unitType) = QUOTE(Sharpshooter);
    };
    class A3U_Rivals_Militia_Crew : A3U_Rivals_Partisan {
        displayName = "Crew";
        role = "Crew";
        GVAR(unitType) = QUOTE(Crew);
    };
    class A3U_Rivals_Militia_Pilot : A3U_Rivals_Partisan {
        displayName = "Pilot";
        role = "Pilot";
        GVAR(unitType) = QUOTE(Pilot);
    };
    class A3U_Rivals_Militia_Unarmed : A3U_Rivals_Partisan {
        displayName = "Unarmed";
        role = "Unarmed";
        GVAR(unitType) = QUOTE(Unarmed);
    };
};
