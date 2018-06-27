#pragma once
#include <string>

class Item {
public:
    Item() {}
    Item(std::string name);
    Item(std::string name, bool active, bool equipable);

    void setActive(bool active);
    void setEquipable(bool equipable);

    std::string getName() { return m_name; }
    bool isActive() { return m_active; }
    bool isEquipable() { return m_equipable; }
private:
    std::string m_name;
    bool m_active;
    bool m_equipable;
};