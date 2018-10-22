#pragma once
#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>
#include "../entities/Actor.hpp"
#include "../map/Map.hpp"
#include "../custom/Color.hpp"
#include "../global.hpp"
#include "../entities/Inventory.hpp"
using namespace bt;

void Player::moveEvent() {
   logger.info("Actor moved from: (" + std::to_string(prevPos.x) + "," + std::to_string(prevPos.y) + ") to: (" + std::to_string(pos.x) + "," + std::to_string(pos.y) + ")");
}
void Player::collisionEvent() {
    Tile tile = map.getTileAt(prevPos.x, prevPos.y);
    if (tile.type == "door") {
        logger.info("Colliding with door.");
    } else {
        logger.info("Player collided with tile at: (" + std::to_string(tile.getPosition().x) + "," + std::to_string(tile.getPosition().y) + ")");
    }
}
