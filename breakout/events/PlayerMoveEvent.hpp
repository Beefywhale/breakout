#pragma once
#include "../custom/Event.hpp"
#include "../entities/Player.hpp"
#include "../map/Map.hpp"
#include "../global.hpp"

class PlayerMoveEvent: public Event {
public:
    PlayerMoveEvent(): Event() {};

    void emit(Player player, Map map) {
        logger.info("Player moved from: (" + std::to_string(player.prevPos.x) + "," + std::to_string(player.prevPos.y) + ") to: (" + std::to_string(player.getPosition().x) + "," + std::to_string(player.getPosition().y) + ")");
    }
};
