#pragma once
#include <string>

class Item {
public:
    Item();

    void setActive(bool active);
    void setEquipable(bool equipable);
    void setName(std::string name);


    std::string getName() { return m_name; }

    bool active() { return m_active; }
    bool equipable() { return m_equipable; }
private:
    std::string m_name;

    bool m_active;
    bool m_equipable;
};
