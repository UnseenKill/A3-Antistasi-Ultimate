class A3OVG_Config_Base {
    class Callbacks;
    class Storage {
        class Adapter_NS;
    };
};

class A3OVG_Config: A3OVG_Config_Base {
    scope = 1;

    class Callbacks: Callbacks {
        // (Void [String hintTextStructured]) Show UI hint texts to the player
        uiShowHint = QUOTE([ARR_2(QQUOTE(A3OVG),_this select 0)] call FUNCMAIN(customHint));
    };

    class Storage: Storage {
        defaultAdapter = QUOTE(Adapter_NS);

        class Adapter_NS: Adapter_NS {
            autoCommit = 0;
        };
    };
};
