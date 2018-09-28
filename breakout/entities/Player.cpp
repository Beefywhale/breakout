#include "../events/PlayerMoveEvent.hpp"
#include "../events/CollisionEvent.hpp"
#include "Player.hpp"

void Player::update() {
    if (static_cast<int>(walkClock.getElapsedTime().asMilliseconds() >= 80)) {
        canWalk = true;
    }
}

void Player::safeMove(int x, int y, Map map) {
    if (canWalk) {
        Tile tileAt = map.getTileAt(pos.x + x, pos.y + y);
        if (tileAt.solid()) {
            //add a collision event to the event queue
            prevPos.x = tileAt.getPosition().x;
            prevPos.y = tileAt.getPosition().y;
            Event* newEvent = new CollisionEvent();
            eventHandler.addEvent(newEvent);
        }
        else {
            //add playermove event to queue
            Event* newEvent = new PlayerMoveEvent();
            eventHandler.addEvent(newEvent);
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
