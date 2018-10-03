#pragma once
#include "../custom/Event.hpp"
#include "../entities/Player.hpp"
#include "../map/Tile.hpp"
#include "../map/Map.hpp"
#include "../global.hpp"

class CollisionEvent: public Event {
public:
    CollisionEvent(): Event() {};

    void emit(Actor actor, Map map) {
        Tile tile = map.getTileAt(actor.prevPos.x, actor.prevPos.y);
        if (tile.type == "door") {
            logger.info("Colliding with door.");
        } else {
            logger.info("Player collided with tile at: (" + std::to_string(tile.getPosition().x) + "," + std::to_string(tile.getPosition().x) + ")");
        }
    }
};
