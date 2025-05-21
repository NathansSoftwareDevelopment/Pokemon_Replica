#ifndef TYPE_H
#define TYPE_H
#include <string>
#include <map>

class Type {
    public:
        std::string typeName;

        double attackingNormal;
        double attackingFire;
        double attackingWater;
        double attackingElectric;
        double attackingGrass;
        double attackingIce;
        double attackingFighting;
        double attackingPoison;
        double attackingGround;
        double attackingFlying;
        double attackingPsychic;
        double attackingBug;
        double attackingRock;
        double attackingGhost;
        double attackingDragon;
        double attackingDark;
        double attackingSteel;
        double attackingNone;
        double* attackingStats[18] = {
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
        std::map<std::string, double> attackingTypeMap;

        Type(std::string typeInputName, double attackingInputStats[18]);
};

extern std::map<std::string, Type> typeMap;

#endif