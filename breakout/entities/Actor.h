#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "../custom/Color.h"
using namespace bt;

/**
<<<<<<< HEAD
* @brief Actor.
*/
class Actor {
public:
    /**
     * Default constructor for Actor.
     */
    Actor();
    
    /**
=======
* @brief Actor class
*/
class Actor {
public:
	/**
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
	 * Position struct with x and y members for coordinates.
	 */
	 struct position {
        int x; /**< Actor's position on the X axis. */
        int y; /**< Actor's position on the Y axis. */
    };

<<<<<<< HEAD
=======
    Actor();

>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
    /**
	 * Create a new Actor at an x and y position, with text and a color.
	 * @param x Actor's starting x position.
	 * @param y Actor's starting y position.
	 * @param pCh Actor's text representing them in-game.
	 * @param pColor Color of the Actor's text.
	 */
    Actor(int x, int y, wchar_t pCh, Color pColor);

   /**
	* Get the Actor's current x and y position.
	* @return A position struct with the Actor's current x and y position.
	*/
	position getPosition() { return pos; }

   /**
	* Get the current text representing the Actor.
	* @return the character of the Actor.
	*/
    wchar_t getChar() { return ch; }

   /**
	* Get the current BColor of the Actor.
	* @return The color of the Actor.
	*/
	Color getColor() { return color; }

   /**
	* Move the Actor to a new x and y position.
	* @param x new position on the x axis for the Actor.
	* @param y new position on the y axis for the Actor.
	*/
    void setPosition(int x, int y);

   /**
	* Move the Actor by an offset.
	* @param x amount to offset the Actor on the x axis.
	* @param y amount to offset the Actor on the y axis.
	*/
    void move(int x, int y);

   /**
	* Update the Actor every game loop.
	*/
	virtual void update() {};

   /**
	* Calculate the distance between two sets of coordinates.
	* @param startX starting x position.
	* @param startY starting y position.
	* @param targetX the target's x position.
	* @param targetY the target's y position.
	* @return The calculated distance between the two sets of coordinates.
	*/
	int distance(int startX, int startY, int targetX, int targetY);

   /**
	* Get the Actor's sight radius.
	* @return The Actor's sight radius.
	*/
	int getSight() { return radius; }
private:
    wchar_t ch;
    Color color;
	int radius = 3; // eventually won't be a constant
protected:
   /**
	* Position of Actor on X and Y using the position struct.
	*/
    position pos;
};
