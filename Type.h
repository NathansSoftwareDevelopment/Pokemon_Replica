#ifndef TYPE_H
#define TYPE_H
#include <string>
#include <map>

class Type {
    public:
        std::string name;

        std::map<std::string, double> attackingTypeMap;

        Type(std::string typeInputName, std::map<std::string, double> inputAttackingTypeMap);
};

extern std::map<std::string, Type> typeMap;

#endif