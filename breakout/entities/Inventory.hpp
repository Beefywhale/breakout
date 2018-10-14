#pragma once
#include <map>
#include <vector>
#include <string>
#include "../map/Item.hpp"

// Class: Inventory
// A class for handling <Item>s
class Inventory {
public:
    Inventory() {}

    void addItem(Item newItem);

    std::vector<Item> getItemsNamed(std::string item);
    std::map<std::string, std::vector<Item> > getItems() { return items; }

    void removeItems(std::string itemName, int amount);
    void removeItems(Item item, int amount);

private:
    std::map<std::string, std::vector<Item> > items;
};
