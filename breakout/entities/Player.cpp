#include "Player.h"

Player::Player() {}

void Player::update(Map map) {
    if ((int)walkClock.getElapsedTime().asMilliseconds() >= 100) {
        canWalk = true;
    }
    if (canWalk) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			Tile tileAt = map.getTileAt(pos.x - movementSpeed, pos.y);
			if (tileAt.isSolid()) {
				tileAt.getType().collide();
			} else {
				move(-movementSpeed, 0);
				canWalk = false;
				walkClock.restart();
			}
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			Tile tileAt = map.getTileAt(pos.x + movementSpeed, pos.y);
			if (tileAt.isSolid()) {
				tileAt.getType().collide();
			} else {
				move(movementSpeed, 0);
				canWalk = false;
				walkClock.restart();
			}
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			Tile tileAt = map.getTileAt(pos.x, pos.y + movementSpeed);
			if (tileAt.isSolid()) {
				tileAt.getType().collide();
			} else {
				move(0, movementSpeed);
				canWalk = false;
				walkClock.restart();
			}
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			Tile tileAt = map.getTileAt(pos.x, pos.y - movementSpeed);
			if (tileAt.isSolid()) {
				tileAt.getType().collide();
			} else {
				move(0, -movementSpeed);
				canWalk = false;
				walkClock.restart();
			}
		}
    }
}

void Player::setWalk(bool p_walk) {
    canWalk = p_walk;
}
