#include "Item.h"

Item::Item() {
    m_active = true;
    m_equipable = true;
    m_name = "";
}

void Item::setActive(bool active) {
    m_active = active;
}

void Item::setEquipable(bool equipable) {
    m_equipable = equipable;
}

void Item::setName(std::string name) {
    m_name = name;
}