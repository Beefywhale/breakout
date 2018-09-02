#pragma once
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "../libs/json.hpp"
#include <SFML/Graphics.hpp>
#include "../global.hpp"
#include "Tile.hpp"
#include "../Logger.hpp"
using json = nlohmann::json;

// Class: Map
// A map of <Tile>.
class Map {
public:
    // Group: Functions

    // Contructor: Map
    // Default contructor.
    Map() {};
	
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

    void load(const std::string path);
    void save(const std::string path);

private:
    // Group: Private Variables

    // Variable: tileMap
    std::map<std::pair<int, int>, Tile> tileMap;

    // Variable: it
    std::map<std::pair<int, int>, Tile>::iterator it;
    
    // Variable: logger    
    Logger logger;

    // Variable: m_path
    std::string m_path;

    // Variable: data
    json data;

    // Variable: typeMap
    std::map<std::string, Type::Types> string2Type {
        std::make_pair("floor", Type::Floor),
		std::make_pair("door", Type::Door),
		std::make_pair("wall", Type::Wall)
	};

    std::map<Type::Types, std::string> type2String {
        std::make_pair(Type::Floor, "floor"),
		std::make_pair(Type::Door, "door"),
		std::make_pair(Type::Wall, "wall")
	};

    // Variable: mapData
    struct {
        struct {
            int x;
            int y;
        } spawnpoint;
    } mapData;
};
