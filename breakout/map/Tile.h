#pragma once
#include <SFML/Graphics.hpp>
#include "Type.h"

class Tile {
public:
    /**
	 * Position struct with x and y members for coordinates.
	 */
	 struct position {
		 int x; /**< Tile's position on the X axis. */
		 int y; /**< Tile's position on the Y axis. */
	 };

    Tile();
    
   /**
	* Create a new Tile at an x and y position, with text and a color.
	* @param x Tile's starting x position.
	* @param y Tile's starting y position.
	* @param pCh Tile's text representing it in-game.
	* @param pColor Color of the Tiles's text.
	* @param pSolid Whether the Tile is solid or not.
	*/
	Tile(int x, int y, wchar_t pCh, sf::Color pColor, bool pSolid);
    
	
   /**
	* Get the current text representing the Tile.
	* @return the character of the Tile.
	*/
	wchar_t getChar() { return ch; }

   /**
	* Get the current sf::Color of the Tile.
	* @return The color of the Tile.
	*/
	sf::Color getColor() { return color; }
    
   /**
	* Get the Tile's current x and y position.
	* @return A position struct with the Tile's current x and y position.
	*/
	position getPosition() { return pos; }

   /**
	* Check if this Tile is solid or not.
	* @return A bool that is true if solid and false if not.
	*/
	bool isSolid() { return solid; }

   /**
	* Get the Type of this Tile.
	* @return This Tile's Type.
	*/
	Type getType() { return type; }

   /**
	* Set the Type of this Tile.
	* @param newType The new Type for this Tile.
	*/
	void setType(Type newType);


private:
    position pos;
    wchar_t ch;
    sf::Color color;
    bool solid;
	Type type = Type("default");
};