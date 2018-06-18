#pragma once
#include <string>

class Item {
public:
    Item() {}
    Item(std::string pName);
    Item(std::string pName, bool pActive, bool pEquipable);

    void setActive(bool pActive);
    void setEquipable(bool pEquipable);

    std::string getName() { return name; }
    bool isActive() { return active; }
    bool isEquipable() { return equipable; }
private:
    std::string name;
    bool active;
    bool equipable;
};