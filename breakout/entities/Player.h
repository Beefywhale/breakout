#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Actor.hpp"
#include "../map/Map.hpp"
#include "../custom/Color.hp"
#include "../global.hpp"
#include "Inventory.hpp"

using namespace bt;

// Class: Player
// A class that extends the use of Actor for a controllable player.
class Player: public Actor {
public:
    // Group: Functions

    // Constructor: Player
    // Default constructor.
    Player() {}

    /* Constructor: Player
       Init a Player at an x and y position, with text and color.

       Parameters:
          x - starting x position.
          y - starting y position.
          ch - Player text char.
          color - <Color> of the text.
        
        See Also:
           <Actor>
    */
    Player(int x, int y, wchar_t ch, Color color) : Actor(x, y, ch, color) {}

    //Function: Update
    //Called every frame of the game.    
	void update() override;

    /* Function: setWalk
       Sets whether the player can walk or not.

       Parameters:
          walk - Boolean to set if the player can walk.    
    */
	void setWalk(bool walk);

    /* Function: safeMove
       Move Player to an x,y offset while checking collision and timings.

       Parameters:
          x - offset to add to the current x position.   
          y - offset to add to the current y position.
          map - the current <Map>.
    */
    void safeMove(int x, int y, Map map);

    /* Function: getInventory
       Get the current <Inventory> of the Player.

       Returns:
          The Player <Inventory>.
       
       See Also:
          <Actor::setPosition>
    */
    Inventory* getInventory() { return inv; }

    // Variable: movementSpeed
    // The speed at which the Player can move in one keypress.
    int movementSpeed = 1;

    // Variable: canWalk
    // true if the Player can walk, false else.
    bool canWalk = true;
private:
    // Group: Private Variables
    
    // Variable: walkClock
    sf::Clock walkClock;

    // Variable: inv
    // The Player <Inventory>.
    Inventory* inv = new Inventory;
};
