#include "Item.h"

Item::Item(std::string pName) {
    name = pName;
}

Item::Item(std::string pName, bool pActive, bool pEquipable) {
    name = pName;
    active = pActive;
    equipable = pEquipable;
}

void Item::setActive(bool pActive) {
    active = pActive;
}

void Item::setEquipable(bool pEquipable) {
    equipable = pEquipable;
}

