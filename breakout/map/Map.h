#pragma once
#include <vector>
#include <map>
#include <utility>
#include "../global.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "../Logger.h"

/**
<<<<<<< HEAD
* @brief Map.
*/
class Map {
public:
    /**
     * Default constructor for Map.
     */
=======
* @brief Map class
*/
class Map {
public:
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
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
<<<<<<< HEAD
	* @return The Tile at the x and y coordinates.
	*/
    Tile getTileAt(int x, int y);

=======
	* @return A Tile with the same x and y coordinates.
	*/
    Tile getTileAt(int x, int y);
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
private:
    std::map<std::pair<int, int>, Tile> tileMap;
    std::map<std::pair<int, int>, Tile>::iterator it;
    Logger logger;
};
