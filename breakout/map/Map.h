#pragma once
#include <vector>
#include "../global.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "../Logger.h"

/**
* @brief Map class
*/
class Map {
public:
    Map();
	
   /**
	* Get all of the Map's Tiles in a vector.
	* @return a vector of Tiles.
	*/
    std::vector<Tile> getTiles() { return tileMap; }

   /**
	* Get the Tile at a specific set of coordinates
	* @param x The x coordinate of the tile you want.
	* @param y The y coordinate of the tile you want.
	* @return A Tile with the same x and y coordinates.
	*/
    Tile getTileAt(int x, int y);
private:
    std::vector<Tile> tileMap;
    Logger logger;
};
