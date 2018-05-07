#pragma once
#include "iostream"
#include <functional>

class Type {
public:
	Type();
	Type(std::string pName);
	Type(std::string pName, const std::function<void()>& f) : collideOverride(f) { name = pName; }
	std::string name;
	void collide() { collideOverride(); }
private:
	std::function<void()> collideOverride;
};