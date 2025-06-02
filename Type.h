#ifndef TYPE_H
#define TYPE_H
#include <string>
#include <map>

class Type {
    private:
        std::string _name;
        std::map<std::string, double> _attackingTypeMap;
    public:
        const std::string name() const {return _name;}
        const std::map<std::string, double> attackingTypeMap() const {return _attackingTypeMap;}
        
        Type(std::string typeInputName, std::map<std::string, double> inputAttackingTypeMap);
};

extern std::map<std::string, Type> typeMap;

#endif