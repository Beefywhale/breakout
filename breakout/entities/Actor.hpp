#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "../custom/Color.hpp"
using namespace bt;

/* Struct: Actor::position
	Position struct with x and y fields.

	Fields:
		x - Actor x position.
		y - Actor y position.
*/
struct position {
	int x;
	int y;
};

// Class: Actor
// A class used for in-game actors.
class Actor {
public:
	// Group: Functions

	// Constructor: Actor
	// Default constructor.
    Actor() {}

    /**
	 * Create a new Actor at an x and y position, with text and a color.
	 * @param x Actor's starting x position.
	 * @param y Actor's starting y position.
	 * @param ch Actor's text representing them in-game.
	 * @param color Color of the Actor's text.
	 */
	/* Constructor: Actor
	   Init a Player at an x and y position, with text and color.

	   Parameters:
          x - starting x position.
          y - starting y position.
          ch - Player text char.
          color - <Color> of the text.
	*/
    Actor(int x, int y, wchar_t ch, Color color);

   /**
	* Get the Actor's current x and y position.
	* @return A position struct with the Actor's current x and y position.
	*/
	/* Function: getPosition
	   Get the Actor position.

	   Returns:
	      The current Actor position.

	   See Also:
	      <position>
	*/
	position getPosition() { return pos; }

	/* Function: getChar
	   Get the Actor text char.

	   Returns:
	      The Actor char.
	*/
    wchar_t getChar() { return m_ch; }

	/* Function: getColor
	   Get the Actor color.

	   Returns:
	      The Actor color.

	   See Also:
	      <Color>
	*/
	Color getColor() { return m_color; }

   /**
	* Move the Actor by an offset.
	* @param x amount to offset the Actor on the x axis.
	* @param y amount to offset the Actor on the y axis.
	*/
	/* Function: move
	   Move Actor by an offset.

	   Parameters:
	      x - offset to add to the current x position.
          y - offset to add to the current y position.
	*/
    void move(int x, int y);

	//Function: Update
    //Called every frame of the game.
	virtual void update() {}

	/* Function: distance
	   Calculate the distance between two sets of coordinates.

	   Parameters:
	      startX - starting x position.
	      startY - starting y position.
	      targetX - target x position.
	      targetX - target x position.
	*/
	int distance(int startX, int startY, int targetX, int targetY);

	/* Function: sight
	   Get the Actor sight radius.

	   Returns:
	      The Actor sight radius.
	*/
	int sight() { return m_radius; }

	/* Function: setPosition
	   Move Actor to a desired x and y position.

	   Parameters:
	      x - position on the X axis.
	      y - position on the Y axis.
	*/
    void setPosition(int x, int y);

	/* Function: setSightRadius
	   Set Actor sight radius.

	   Parameters:
	      radius - The new sight radius.
	*/
	void setSightRadius(int radius);

private:
	//Group: Private Variables

	// Variable: m_ch
    wchar_t m_ch;

	// Variable: m_color
    Color m_color;

	// Variable: m_radius
	int m_radius = 3;

protected:
	// Group: Protected Variables

	// Variable: pos
    position pos;
};
