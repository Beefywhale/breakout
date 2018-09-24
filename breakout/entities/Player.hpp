#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Actor.hpp"
#include "../map/Map.hpp"
#include "../custom/Color.hpp"
#include "../global.hpp"
#include "Inventory.hpp"

using namespace bt;

class Player: public Actor {
public:
    Player() {}

    Player(int x, int y, wchar_t ch, Color color) : Actor(x, y, ch, color) {}

	void update() override;
	void setWalk(bool walk);
    void safeMove(int x, int y, Map map);

    Inventory* getInventory() { return inv; }

    int movementSpeed = 1;

    bool canWalk = true;
private:
    sf::Clock walkClock;

    Inventory* inv = new Inventory;
};
