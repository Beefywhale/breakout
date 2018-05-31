#pragma once
#include <vector>
#include <map>
#include <utility>
#include "../global.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "../Logger.h"

/**
* @brief Map.
*/
class Map {
public:
    /**
     * Default constructor for Map.
     */
    Map();
	
   /**
	* Get all of the Map's Tiles in a std::map.
	* @return a std::map with x,y pair key and Tile value.
	*/
    std::map<std::pair<int, int>, Tile> getTiles() { return tileMap; }

   /**
	* Get the Tile at a specific set of coordinates
	* @param x The x coordinate of the tile you want.
	* @param y The y coordinate of the tile you want.
	* @return The Tile at the x and y coordinates.
	*/
    Tile getTileAt(int x, int y);

private:
    std::map<std::pair<int, int>, Tile> tileMap;
    std::map<std::pair<int, int>, Tile>::iterator it;
    Logger logger;
};
