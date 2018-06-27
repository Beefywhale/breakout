#include "Player.h"

void Player::update() {
    if (static_cast<int>(walkClock.getElapsedTime().asMilliseconds() >= 100)) {
        canWalk = true;
    }
}

void Player::safeMove(int x, int y, Map map) {
    if (canWalk) {
        Tile tileAt = map.getTileAt(pos.x + x, pos.y + y);
        if (tileAt.solid()) {
            //add a collision event to the event queue
            Event* newEvent = new Event();
            newEvent->type = Event::Collision;
            std::shared_ptr<Tile> newTile = std::make_shared<Tile>(tileAt);
            newEvent->collision->tile = newTile;
            eventHandler.addEvent(newEvent);
        }
        else {
            move(x, y);
        }
        canWalk = false;
        walkClock.restart();
    }
}

void Player::setWalk(bool walk) {
    canWalk = walk;
}
