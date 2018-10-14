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

class Player: public Actor {
public:
    Player() {}
    Player(int x, int y, wchar_t ch, Color color) : Actor(x, y, ch, color) {}

	void update() override;
    void setWalk(bool walk);
    void safeMove(int x, int y);
    void setMap(Map mapset) { map = mapset; }

    void moveEvent();
    void collisionEvent();

    Inventory* getInventory() { return inv; }

    int movementSpeed = 1;
    bool canWalk = true;
private:
    sf::Clock walkClock;
    Map map;
    Inventory* inv = new Inventory;
};
