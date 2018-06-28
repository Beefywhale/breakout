#pragma once
#include <vector>
#include <map>
#include <utility>
#include "../global.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "../Logger.h"

// Class: Map
// A map of <Tile>.
class Map {
public:
    // Group: Functions

    // Contructor: Map
    // Default contructor.
    Map();
	
    /* Function: getTiles()
       Get all of the Map <Tile>s in an std::map.
       
       Returns:
          An std::map with x,y pair keys and <Tile> values.
    */
    std::map<std::pair<int, int>, Tile> getTiles() { return tileMap; }

   /**
	* Get the Tile at a specific set of coordinates
	* @param x The x coordinate of the tile you want.
	* @param y The y coordinate of the tile you want.
	* @return The Tile at the x and y coordinates.
	*/
    /* Function: getTileAt
       Get a <Tile> at a specific set of coordinates.

       Parameters:
          x - The x coordinate of the <Tile>.
          y - The y coordinate of the <Tile>.
       
       Returns:
          The <Tile> at the x and y coordinates given.
        
       See Also:
          <Tile>
    */
    Tile getTileAt(int x, int y);

private:
    // Group: Private Variables

    // Variable: tileMap
    std::map<std::pair<int, int>, Tile> tileMap;

    // Variable: it
    std::map<std::pair<int, int>, Tile>::iterator it;
    
    // Variable: logger    
    Logger logger;
};
