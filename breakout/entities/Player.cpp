#include "Player.h"

Player::Player() {}

void Player::update(Map map) {
    if ((int)walkClock.getElapsedTime().asMilliseconds() >= 100) {
        canWalk = true;
    }
    if (canWalk) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && map.getTileAt(pos.x - movementSpeed, pos.y).isSolid()) {
            move(-movementSpeed, 0);
            canWalk = false;
            walkClock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && map.getTileAt(pos.x + movementSpeed, pos.y).isSolid()) {
			move(movementSpeed, 0);
			canWalk = false;
            walkClock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && map.getTileAt(pos.x, pos.y + movementSpeed).isSolid()) {
			move(0, movementSpeed);
			canWalk = false;
            walkClock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && map.getTileAt(pos.x, pos.y - movementSpeed).isSolid()) {
			move(0, -movementSpeed);
			canWalk = false;
            walkClock.restart();
        }
    }
}

void Player::setWalk(bool p_walk) {
    canWalk = p_walk;
}
