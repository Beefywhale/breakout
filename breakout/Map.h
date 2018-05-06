#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "map/Tile.h"

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
};