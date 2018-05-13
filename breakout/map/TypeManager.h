#pragma once
#include <map>
#include "Type.h"

class TypeManager
{
public:
    TypeManager();

    void addType(Type newType);

    std::map<std::string, Type> getTypes() { return types; }

private:
    std::map<std::string, Type> types;
};

