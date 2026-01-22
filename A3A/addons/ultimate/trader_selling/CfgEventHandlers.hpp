class Extended_PreInit_EventHandlers {
    class SUBADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

class Extended_InitPost_EventHandlers {
    class ReammoBox_F {
        class SUBADDON {
            serverInit = QUOTE(call FUNC(addVanillaSellInteraction));
        };
    };
};
