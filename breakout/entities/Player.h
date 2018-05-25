#pragma once
#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "../map/Map.h"
#include "../custom/Color.h"
using namespace bt;

/**
* @brief Player class
*/
class Player: public Actor {
public:
    Player();

	/**
	* Create a new Player at an x and y position, with text and a color.
	* @param x Player's starting x position.
	* @param y Player's starting y position.
	* @param pCh Player's text representing them in-game.
	* @param pColor Color of the Player's text.
	*/
    Player(int x, int y, wchar_t pCh, Color pColor) : Actor(x, y, pCh, pColor) {}

   /**
    * Called every game loop, used for input and collision detection.
    */
	void update();

   /**
	* Set whether the player can walk or not.
	* @param pWalk A bool to set if the player can walk.
	*/
	void setWalk(bool pWalk);
    
    void safeMove(int x, int y, Map map);

    int movementSpeed = 1;
    bool canWalk = true;

private:
    sf::Clock walkClock;
};
