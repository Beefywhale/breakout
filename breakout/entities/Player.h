#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "../map/Map.h"
#include "../custom/Color.h"
#include "../global.h"
#include "Inventory.h"

using namespace bt;

/**
* @brief Player.
*/
class Player: public Actor {
public:
   /**
    * Default constructor for Player.
    */
    Player() {}

   /**
	* Create a new Player at an x and y position, with text and a color.
	* @param x Player's starting x position.
	* @param y Player's starting y position.
	* @param ch Player's text representing them in-game.
	* @param color Color of the Player's text.
	*/
    Player(int x, int y, wchar_t ch, Color color) : Actor(x, y, ch, color) {}

   /**
    * Called every game loop, used for input and collision detection.
    */
	void update() override;

   /**
	* Set whether the player can walk or not.
	* @param walk A bool to set if the player can walk.
	*/
	void setWalk(bool walk);
   
    /**
     * Move the Player while checking collision and timings.
     */
    void safeMove(int x, int y, Map map);

    Inventory* getInventory() { return inv; }

    int movementSpeed = 1;
    bool canWalk = true;
private:
    sf::Clock walkClock;
    Inventory* inv = new Inventory;
};
