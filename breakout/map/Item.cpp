#include "Item.h"

Item::Item(std::string name) {
    m_name = name;
}

Item::Item(std::string name, bool active, bool equipable) {
    m_name = name;
    m_active = active;
    m_equipable = equipable;
}

void Item::setActive(bool active) {
    m_active = active;
}

void Item::setEquipable(bool equipable) {
    m_equipable = equipable;
}

