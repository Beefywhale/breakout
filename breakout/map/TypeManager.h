#pragma once
#include <map>
#include "Type.h"

<<<<<<< HEAD
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
=======
class TypeManager
{
public:
    TypeManager();

    void addType(Type newType);

>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
    std::map<std::string, Type> getTypes() { return types; }

private:
    std::map<std::string, Type> types;
};

