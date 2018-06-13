#include "Player.h"

Player::Player() {
}

void Player::update() {
    if ((int)walkClock.getElapsedTime().asMilliseconds() >= 100) {
        canWalk = true;
    }
}

void Player::safeMove(int x, int y, Map map) {
    if (canWalk) {
        Tile tileAt = map.getTileAt(pos.x + x, pos.y + y);
        if (tileAt.isSolid()) {
            tileAt.getType().collide();
        } else {
            move(x, y);
            canWalk = false;
            walkClock.restart();
        }
    }
}

void Player::setWalk(bool p_walk) {
    canWalk = p_walk;
}
