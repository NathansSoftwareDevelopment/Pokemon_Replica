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
        std::map<std::string, double*> attackingTypeMap = {
            {"Normal", &attackingNormal},
            {"Fire", &attackingFire},
            {"Water", &attackingWater},
            {"Electric", &attackingElectric},
            {"Grass", &attackingGrass},
            {"Ice", &attackingIce},
            {"Fighting", &attackingFighting},
            {"Poison", &attackingPoison},
            {"Ground", &attackingGround},
            {"Flying", &attackingFlying},
            {"Psychic", &attackingPsychic},
            {"Bug", &attackingBug},
            {"Rock", &attackingRock},
            {"Ghost", &attackingGhost},
            {"Dragon", &attackingDragon},
            {"Dark", &attackingDark},
            {"Steel", &attackingSteel},
            {"None", &attackingNone}
        };

        Type(std::string typeInputName, double attackingInputStats[18]);
};

extern std::map<std::string, Type> typeMap;

#endif