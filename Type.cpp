#include "Type.h"
#include <string>
#include <map>

Type::Type(std::string typeInputName, std::map<std::string, double> inputAttackingTypeMap) {
    name = typeInputName;
    attackingTypeMap = inputAttackingTypeMap;
}

std::map<std::string, Type> typeMap = {
    {"Normal", Type(
        "Normal", {
                {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 0.5}, {"Ghost", 0.0}, {"Dragon", 1.0},
                {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Fire", Type(
        "Fire", {
                {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 0.5}, {"Electric", 1.0}, {"Grass", 2.0},
                {"Ice", 2.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 1.0}, {"Bug", 2.0}, {"Rock", 0.5}, {"Ghost", 1.0}, {"Dragon", 0.5},
                {"Dark", 1.0}, {"Steel", 2.0}, {"None", 1.0}
            }
        )
    },
    {"Water", Type(
        "Water", {
                {"Normal", 1.0}, {"Fire", 2.0}, {"Water", 0.5}, {"Electric", 1.0}, {"Grass", 0.5},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 2.0}, {"Flying", 1.0},
                {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 2.0}, {"Ghost", 1.0}, {"Dragon", 0.5},
                {"Dark", 1.0}, {"Steel", 1.0}, {"None", 1.0}
            }
        )
    },
    {"Electric", Type(
        "Electric", {
                {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 2.0}, {"Electric", 0.5}, {"Grass", 0.5},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 0.0}, {"Flying", 2.0},
                {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 0.5},
                {"Dark", 1.0}, {"Steel", 1.0}, {"None", 1.0}
            }
        )
    },
    {"Grass", Type(
        "Grass", {
                {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 2.0}, {"Electric", 1.0}, {"Grass", 0.5},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 0.5}, {"Ground", 2.0}, {"Flying", 0.5},
                {"Psychic", 1.0}, {"Bug", 0.5}, {"Rock", 2.0}, {"Ghost", 1.0}, {"Dragon", 0.5},
                {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Ice", Type(
        "Ice", {
                {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 0.5}, {"Electric", 1.0}, {"Grass", 2.0},
                {"Ice", 0.5}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 2.0}, {"Flying", 2.0},
                {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 2.0},
                {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Fighting", Type(
        "Fighting", {
                {"Normal", 2.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                {"Ice", 2.0}, {"Fighting", 1.0}, {"Poison", 0.5}, {"Ground", 1.0}, {"Flying", 0.5},
                {"Psychic", 0.5}, {"Bug", 0.5}, {"Rock", 2.0}, {"Ghost", 0.0}, {"Dragon", 1.0},
                {"Dark", 2.0}, {"Steel", 2.0}, {"None", 1.0}
            }
        )
    },
    {"Poison", Type(
        "Poison", {
                {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 2.0},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 0.5}, {"Ground", 0.5}, {"Flying", 1.0},
                {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 0.5}, {"Ghost", 0.5}, {"Dragon", 1.0},
                {"Dark", 1.0}, {"Steel", 0.0}, {"None", 1.0}
            }
        )
    },
    {"Ground", Type(
        "Ground", {
                {"Normal", 1.0}, {"Fire", 2.0}, {"Water", 1.0}, {"Electric", 2.0}, {"Grass", 0.5},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 2.0}, {"Ground", 1.0}, {"Flying", 0.0},
                {"Psychic", 1.0}, {"Bug", 0.5}, {"Rock", 2.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                {"Dark", 1.0}, {"Steel", 2.0}, {"None", 1.0}
            }
        )
    },
    {"Flying", Type(
        "Flying", {
                {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 0.5}, {"Grass", 2.0},
                {"Ice", 1.0}, {"Fighting", 2.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 1.0}, {"Bug", 2.0}, {"Rock", 0.5}, {"Ghost", 1.0}, {"Dragon", 1.0},
                {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Psychic", Type(
        "Psychic", {
                {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                {"Ice", 1.0}, {"Fighting", 2.0}, {"Poison", 2.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 0.5}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                {"Dark", 0.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Bug", Type(
        "Bug", {
                {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 2.0},
                {"Ice", 1.0}, {"Fighting", 0.5}, {"Poison", 0.5}, {"Ground", 1.0}, {"Flying", 0.5},
                {"Psychic", 2.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 0.5}, {"Dragon", 1.0},
                {"Dark", 2.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Rock", Type(
        "Rock", {
                {"Normal", 1.0}, {"Fire", 2.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                {"Ice", 2.0}, {"Fighting", 0.5}, {"Poison", 1.0}, {"Ground", 0.5}, {"Flying", 2.0},
                {"Psychic", 1.0}, {"Bug", 2.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Ghost", Type(
        "Ghost", {
                {"Normal", 0.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 2.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 2.0}, {"Dragon", 1.0},
                {"Dark", 0.5}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Dragon", Type(
        "Dragon", {
                {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 2.0},
                {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Dark", Type(
        "Dark", {
                {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                {"Ice", 1.0}, {"Fighting", 0.5}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 2.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 2.0}, {"Dragon", 1.0},
                {"Dark", 0.5}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"Steel", Type(
        "Steel", {
                {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 0.5}, {"Electric", 0.5}, {"Grass", 1.0},
                {"Ice", 2.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 2.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
            }
        )
    },
    {"None", Type(
        "None", {
                {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                {"Dark", 1.0}, {"Steel", 1.0}, {"None", 1.0}
            }
        )
    }
};