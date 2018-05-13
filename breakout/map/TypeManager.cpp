#include "TypeManager.h"

TypeManager::TypeManager() {}

void TypeManager::addType(Type newType) {
    types.insert(std::pair<std::string, Type>(newType.name, newType));
}