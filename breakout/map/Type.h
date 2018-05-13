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
	

    void setCollide(std::function<void()> newCollide) { collideOverride = newCollide; }
    void setUpdate(std::function<void()> newUpdate) { updateOverride = newUpdate; }

    /**
	* Create a Type with a name, and collide function event.
	*/
	void collide() { collideOverride(); }

	std::string name;
private:
	std::function<void()> collideOverride;
    std::function<void()> updateOverride;
};