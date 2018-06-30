#pragma once
#include <SFML/Graphics.hpp>
#include "../entities/Actor.h"
#include "Type.h"
using namespace bt;

// Class: Tile
// A class for tiles.
class Tile: public Actor {
public:
	// Group: Functions

	// Constructor: Tile
	// Default constructor.
    Tile() {}

	// Destructor: Tile
	// Default destructor.
	virtual ~Tile() {}

   /**
	* Create a new Tile at an x and y position, with text and a color.
	* @param x Tile's starting x position.
	* @param y Tile's starting y position.
	* @param ch Tile's text representing it in-game.
	* @param color Color of the Tile's text.
	*/
	/* Constructor: Tile
	   Init a Tile at an x and y position, with text and color

	    Parameters:
           x - starting x position.
           y - starting y position.
           ch - Tile text char.
           color - <Color> of the text.
		
		See Also:
		   <Actor>
	*/
	Tile(int x, int y, wchar_t ch, Color color);

	/* Function: solid
	   Get the Tile solidness.

	   Returns:
	      true if the tile is solid, false else.

	   See Also:
	      <setSolid>
	*/
	bool solid() { return m_solid; }

	/* Function: setSolid
	   Set if the Tile is solid or not.

	   Parameters:
	      solid - Boolean to set if the Tile is solid.

	   See Also:
	      <solid>
	*/
	void setSolid(bool solid);

	// Group: Public Variables

	// Variable: type
	Type* type;

private:
    // Group: Private Variables
    
	// Variable: m_solid
	bool m_solid;
};
