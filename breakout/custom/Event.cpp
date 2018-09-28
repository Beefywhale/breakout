#include "../entities/Player.hpp"
#include "../map/Map.hpp"
#include "Event.hpp"

void Event::setDesc(std::string newDescription) {
    description = newDescription;
}

void Event::emit(Player player, Map map) {}
