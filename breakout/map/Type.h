#pragma once
#include "iostream"
#include <functional>

/**
* @brief Type.
*/
class Type {
public:
   /**
    * Default constructor for Type.
    */
	Type();

   /**
	* Create a Type with just a name.
	* @param pName The name of this Type, EX: "Door".
	*/
    Type(std::string pName);
	
   /**
    * Set a function to be called everytime something collides with a Tile with this Type.
    * @param newCollide A function to be called everytime something collides.
    */
    void setCollide(std::function<void()> newCollide) { collideOverride = newCollide; }
    
   /**
    * Set a function to be called every game update.
    * @param newUpdate A function to be called every game loop.
    */
    void setUpdate(std::function<void()> newUpdate) { updateOverride = newUpdate; }

   /**
	* Create a Type with a name and collide function event.
	*/
	void collide() { collideOverride(); }

	std::string name;
private:
	std::function<void()> collideOverride;
    std::function<void()> updateOverride;
};