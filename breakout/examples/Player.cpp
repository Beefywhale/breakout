#include "Player.hpp"

Player::Player(int x, int y, wchar_t ch, Color color, Map mapset) : Actor(x, y, ch, color) {
    setMap(mapset);
}


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

void Player::update() {
    if (static_cast<int>(walkClock.getElapsedTime().asMilliseconds() >= 80)) {
        canWalk = true;
    }
}

void Player::safeMove(int x, int y) {
    if (canWalk) {
        Tile tileAt = map.getTileAt(pos.x + x, pos.y + y);
        if (tileAt.solid()) {
            //add a collision event to the event queue
            prevPos.x = tileAt.getPosition().x;
            prevPos.y = tileAt.getPosition().y;
            eventHandler.addEvent(std::bind(&Player::collisionEvent, this));
        }
        else {
            eventHandler.addEvent(std::bind(&Player::moveEvent, this));
            prevPos.x = pos.x;
            prevPos.y = pos.y;
            move(x, y);
        }
        canWalk = false;
        walkClock.restart();
    }
}

void Player::setWalk(bool walk) {
    canWalk = walk;
}
