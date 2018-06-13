#pragma once
#include <string>

class Item
{
public:
    Item() {}
    Item(std::string pName);

    std::string getName() { return name; }

private:
    std::string name;
};