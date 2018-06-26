#pragma once
#include <SFML/Graphics.hpp>
#include "../custom/Color.h"
using namespace bt;

/**
* @brief Tile.
*/
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
	Tile(int x, int y, wchar_t pCh, Color pColor, bool pSolid);


   /**
	* Get the current text representing the Tile.
	* @return The character of the Tile.
	*/
	wchar_t getChar() { return ch; }

   /**
	* Get the current Color of the Tile.
	* @return The Color of the Tile.
	*/
	Color getColor() { return color; }

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
private:
    position pos;
    wchar_t ch;
    Color color;
    bool solid;
};
