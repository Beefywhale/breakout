#pragma once
#include <map>
#include "Type.h"

/**
* @brief TypeManager.
*/
class TypeManager {
public:
   /**
    * Default constructor for TypeManager.
    */
    TypeManager();

   /**
    * Add a Type to a map of Types.
    * @param newType Type to add.
    */
    void addType(Type newType);

   /**
    * Get the map of Types.
    * @return Map of Types.
    */
    std::map<std::string, Type> getTypes() { return types; }

private:
    std::map<std::string, Type> types;
};

