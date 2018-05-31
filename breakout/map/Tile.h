#pragma once
#include <SFML/Graphics.hpp>
#include "Type.h"
#include "TypeManager.h"
#include "../custom/Color.h"
using namespace bt;

/**
<<<<<<< HEAD
* @brief Tile.
=======
* @brief Tile class
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
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
<<<<<<< HEAD
	* @return The character of the Tile.
=======
	* @return the character of the Tile.
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
	*/
	wchar_t getChar() { return ch; }

   /**
<<<<<<< HEAD
	* Get the current Color of the Tile.
	* @return The Color of the Tile.
=======
	* Get the current BColor of the Tile.
	* @return The color of the Tile.
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
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
<<<<<<< HEAD

=======
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
private:
    position pos;
    wchar_t ch;
    Color color;
    bool solid;
	Type type = Type("default");
};
