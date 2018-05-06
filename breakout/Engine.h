#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "map/Tile.h"
#include "entities/Player.h"

class Engine {
 public:
    Engine() {}

   /**
	* Preload variables and objects.
	* @param pWindow A RenderWindow* to draw to.
	* @param pMap A Map to get the Tiles from.
	* @param pPlayer A Player to draw and update.
	*/
	Engine(sf::RenderWindow* pWindow, Map pMap, Player pPlayer);
    
   /**
	* Start the game loop. 
	*/
	void start();
    
   /**
	* Get the current Map.
	* @return the Engine's Map.
	*/
	Map getMap() { return map; }

   /**
	* Get the current Player.
	* @return the Engine's Player.
	*/
	Player getPlayer() { return player; }
 private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text tileRender;
    sf::Text playerRender;
	sf::Text zombieRender;
    Map map;
    Player player;
    const int fontSize = 16;
};
