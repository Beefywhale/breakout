#pragma once
#include "../custom/Event.hpp"
#include "../entities/Player.hpp"
#include "../map/Map.hpp"
#include "../global.hpp"

class PlayerMoveEvent: public Event {
public:
    PlayerMoveEvent(): Event() {};

    void emit(Actor actor, Map map) {
        logger.info("Actor moved from: (" + std::to_string(actor.prevPos.x) + "," + std::to_string(actor.prevPos.y) + ") to: (" + std::to_string(actor.getPosition().x) + "," + std::to_string(actor.getPosition().y) + ")");
    }
};
