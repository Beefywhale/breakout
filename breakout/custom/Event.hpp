#pragma once

#include <string>

//foward declaration of PLayer and Map classes
class Player;
class Map;

class Event {
public:
    Event() {};

    void setDesc(std::string newDescription);
    std::string getDesc() { return description; }

    virtual void emit(Player player, Map map);
private:
    std::string description;
};
