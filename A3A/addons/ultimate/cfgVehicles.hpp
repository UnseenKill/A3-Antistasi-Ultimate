#define SCOPESTATICS scope = 0; scopeCurator = 0

class Land_HelipadCircle_F;
class Land_HelipadSquare_F;
class A3AU_RebHelipad_Circle_F: Land_HelipadCircle_F {};
class A3AU_RebHelipad_Square_F: Land_HelipadSquare_F {};

class HouseBase;
class A3U_StaticHolderBase: HouseBase
{
    destrType = "DestructNo";
    scope = 0;
    scopeCurator = 0;
    editorCategory = "A3U_EditorCategory";
    editorSubcategory = "A3U_EditorSubcategoryStatics";
};

class A3U_StaticHolderSmall: A3U_StaticHolderBase
{
    model = QPATHTOFOLDER(data\staticHolders\static_small);
    displayName = "Static Holder (Small)";
    SCOPESTATICS;
};