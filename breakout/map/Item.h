#pragma once
#include <string>

// Class: Item
// A class for creating and handling in-game items.
class Item {
public:
    // Group: Functions

    // Constructor: Item
    // Default constructor.
    Item();

    /* Function: setActive
       Set if the <Item> is active or not.

       Parameters:
          active - A bool to set <m_active> to.
    */
    void setActive(bool active);

    /* Function: setEquipable
       Set if the <Item> is equipable or not.

       Parameters:
          equipable - A bool to set <m_equipable> to.
    */
    void setEquipable(bool equipable);

    /* Function: setName
       Set the <Item> name.

       Parameters:
          name - An std::string to set <m_name> to.
    */
    void setName(std::string name);

    /* Function: getName
       Get the <Item>'s name.

       Returns:
          The <Item>'s <m_name>. 
    */
    std::string getName() { return m_name; }

    /* Function: active
       Get the <Item>'s active state.

       Returns:
          The <Item>'s <m_active>. 
    */
    bool active() { return m_active; }

    /* Function: equipable
       Get the <Item>'s equipable state.

       Returns:
          The <Item>'s <m_equipable>. 
    */
    bool equipable() { return m_equipable; }
private:
    // Group: Private Variables

    // Variable: m_name 
    std::string m_name;

    // Variable: m_active
    bool m_active;

    // Variable: m_equipable
    bool m_equipable;
};