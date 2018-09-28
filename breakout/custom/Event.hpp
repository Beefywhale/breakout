#pragma once

#include <string>
#include "../entities/Actor.hpp"

//foward declaration of Map class
class Map;

class Event {
public:
    Event() {};

    void setDesc(std::string newDescription);
    std::string getDesc() { return description; }

    virtual void emit(Actor actor, Map map);
private:
    std::string description;
};
