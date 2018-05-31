#pragma once
#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "../map/Map.h"
#include "../custom/Color.h"
using namespace bt;

/**
<<<<<<< HEAD
* @brief Player.
*/
class Player: public Actor {
public:
   /**
    * Default constructor for Player.
    */
    Player();

   /**
=======
* @brief Player class
*/
class Player: public Actor {
public:
    Player();

	/**
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
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
<<<<<<< HEAD
   
    /**
     * Move the Player while checking collision and timings.
     */
=======
    
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
    void safeMove(int x, int y, Map map);

    int movementSpeed = 1;
    bool canWalk = true;
<<<<<<< HEAD
=======

>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
private:
    sf::Clock walkClock;
};
