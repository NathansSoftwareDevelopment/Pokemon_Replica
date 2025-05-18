#ifndef TYPE_H
#define TYPE_H
#include <string>

class Type {
    public:
        std::string typeName;

        float attackingNormal;
        float attackingFire;
        float attackingWater;
        float attackingElectric;
        float attackingGrass;
        float attackingIce;
        float attackingFighting;
        float attackingPoison;
        float attackingGround;
        float attackingFlying;
        float attackingPsychic;
        float attackingBug;
        float attackingRock;
        float attackingGhost;
        float attackingDragon;
        float attackingDark;
        float attackingSteel;
        float attackingNone;
        float* attackingStats[18] = {
            &attackingNormal,
            &attackingFire,
            &attackingWater,
            &attackingElectric,
            &attackingGrass,
            &attackingIce,
            &attackingFighting,
            &attackingPoison,
            &attackingGround,
            &attackingFlying,
            &attackingPsychic,
            &attackingBug,
            &attackingRock,
            &attackingGhost,
            &attackingDragon,
            &attackingDark,
            &attackingSteel,
            &attackingNone
        };

        Type(std::string typeInputName, float attackingInputStats[18]);
};

#endif