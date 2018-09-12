#pragma once
#include <map>
#include <vector>
#include <string>
#include "../map/Item.hpp"

// Class: Inventory
// A class for handling <Item>s
class Inventory {
public:
    // Group: Functions

    // Constructor: Inventory
    // Default constructor.
    Inventory() {}

    /* Function: addItem
       Add a new item to <items>

       Parameters:
          newItem - the new item to add.

       See Also:
          <Item>

    */
    void addItem(Item newItem);

    /* Function: getItemsNamed
       get all items in Inventory that have a specified name.

       Parameters:
          item - the name of the item.

       Returns:
          An std::vector with all <Item>s found with the given name.

       See Also:
          <Item>
    */
    std::vector<Item> getItemsNamed(std::string item);

    /* Function: getItems
       get the all of the items in the Inventory.

       Returns:
          The <items> of the Inventory.
    */
    std::map<std::string, std::vector<Item> > getItems() { return items; }

private:
    // Group: Private Variables

    // Variable: items
    std::map<std::string, std::vector<Item> > items;
};
