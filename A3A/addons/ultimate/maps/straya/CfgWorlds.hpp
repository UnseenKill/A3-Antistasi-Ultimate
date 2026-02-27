class CfgWorlds {
    class CAWorld {
        class Names {
            class abandoned_camp;
            class Adelaide;
            class alice;
            class bathurst;
            class Brisbane;
            class Broken_hill;
            class cairns;
            class Coober;
            class darwin;
            class Eden;
            class Launceston;
            class Melbourne;
            class Mil;
            class mount_isa;
            class outpost1;
            class Perth;
            class port_lincoln;
            class rockhampton;
            class smithton;
            class spuds_roadhouse;
            class sydney;
            class Tailem_bend;
            class Weipa;
            class willcania;
        };
    };

    // This is a slipshod map where locations names are either misused as region
    // markers or kept at arbitrary puny radii, so kinda _EVERY_ location needs
    // adjustment as to its size. Also, add a few new locations and convert some.
    class australia: CAWorld {
        class Names: Names {
            class A3U_shanty_0 {
                angle = 310;
                name = "$STR_A3AU_Maps_Straya_Location_Shanty_0";
                position[] = {8734,26176};
                radiusA = 300;
                radiusB = 200;
                type = "Namecity";
            };
            class A3U_shanty_1 {
                angle = 170.203;
                name = "$STR_A3AU_Maps_Straya_Location_Shanty_1";
                position[] = {15801,15121};
                radiusA = 150;
                radiusB = 50;
                type = "NameVillage";
            };
            class A3U_shanty_2 {
                angle = 338;
                name = "$STR_A3AU_Maps_Straya_Location_Shanty_2";
                position[] = {8934,16374};
                radiusA = 184;
                radiusB = 155;
                type = "NameVillage";
            };
            class abandoned_camp: abandoned_camp {
                name = "Davenport";
                radiusA = 200;
                radiusB = 200;
                type = "NameVillage";
            };
            class Adelaide: Adelaide {
                radiusA = 575;
                radiusB = 450;
            };
            class alice: alice {
                radiusA = 420;
                radiusB = 420;
            };
            class bathurst: bathurst {
                angle = 328;
                radiusA = 637;
                radiusB = 170;
            };
            class Brisbane: Brisbane {
                radiusA = 850;
                radiusB = 500;
            };
            class Broken_hill: Broken_hill {
                radiusA = 400;
                radiusB = 400;
            };
            class cairns: cairns {
                angle = 350;
                radiusA = 450;
                radiusB = 250;
            };
            class Coober: Coober {
                radiusA = 300;
                radiusB = 300;
            };
            class darwin: darwin {
                position[] = {16207,33417};
                radiusA = 750;
                radiusB = 500;
            };
            class Eden: Eden {
                radiusA = 300;
                radiusB = 200;
            };
            class Launceston: Launceston {
                radiusA = 150;
                radiusB = 300;
            };
            class Melbourne: Melbourne {
                radiusA = 800;
                radiusB = 800;
            };
            class Mil: Mil {
                radiusA = 300;
                radiusB = 300;
            };
            class mount_isa: mount_isa {
                radiusA = 200;
                radiusB = 150;
            };
            class outpost1: outpost1 {
                angle = 350;
                name = "$STR_A3AU_Maps_Straya_Location_outpost1_Override";
                radiusA = 140;
                radiusB = 61;
                type = "NameVillage";
            };
            class Perth: Perth {
                position[] = {5168,18296};
                radiusA = 850;
                radiusB = 850;
            };
            class port_lincoln: port_lincoln {
                radiusA = 300;
                radiusB = 300;
            };
            class rockhampton: rockhampton {
                radiusA = 400;
                radiusB = 400;
            };
            class smithton: smithton {
                radiusA = 200;
                radiusB = 200;
            };
            class spuds_roadhouse: spuds_roadhouse {
                angle = 315;
                name = "$STR_A3AU_Maps_Straya_Location_SpudsRoadhouse_Override";
                radiusA = 200;
                radiusB = 175;
                type = "NameVillage";
            };
            class sydney: sydney {
                radiusA = 1250;
                radiusB = 850;
            };
            class Tailem_bend: Tailem_bend {
                radiusA = 200;
                radiusB = 200;
            };
            class Weipa: Weipa {
                radiusA = 300;
                radiusB = 300;
            };
            class willcania: willcania {
                radiusA = 500;
                radiusB = 270;
            };
        };
    };
};
