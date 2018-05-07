#pragma once
#include "iostream"
#include <functional>

/**
* @brief Type class
*/
class Type {
public:
	Type();

   /**
	* Create a Type with just a name.
	* @param pName The name of this Type, EX: "Door".
	*/
	Type(std::string pName);

   /**
	* Create a Type with a name, and collide function event.
	* @param pName The name of this Type, EX: "Door".
	* @param f A function to be tied to the collide event.
	*/
	Type(std::string pName, const std::function<void()>& f) : collideOverride(f) { name = pName; }
	
   /**
	* Create a Type with a name, and collide function event.
	*/
	void collide() { collideOverride(); }

	std::string name;
private:
	std::function<void()> collideOverride;
};