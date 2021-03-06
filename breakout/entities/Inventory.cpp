#include "Inventory.hpp"

void Inventory::addItem(Item newItem) {
    if (items.find(newItem.getName()) != items.end()) {
        items[newItem.getName()].push_back(newItem);
    }
    else {
        std::vector<Item> temp;
        temp.push_back(newItem);
        items.insert(std::pair<std::string, std::vector<Item>>(newItem.getName(), temp));
    }
}

std::vector<Item> Inventory::getItemsNamed(std::string itemName) {
    if (items.find(itemName) != items.end()) {
        return items[itemName];
    } else {
        std::vector<Item> temp;
        return temp;
    }
}

//define when I have an id system.
void Inventory::removeItems(std::string itemName, int amount) {}
void Inventory::removeItems(Item item, int amount) {}
