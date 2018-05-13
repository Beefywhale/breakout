#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "map/Tile.h"
#include "entities/Player.h"
#include "map/Type.h"
#include "Map.h"
#include "Logger.h"

/**
* @brief Engine class
*/
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
	* The game loop. 
	*/
	void update();
    
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

   /**
	* Change the font rendering size.
	* @param newSize The new size to set the font to.
	*/
	void changeFontSize(int newSize);

	bool isRunning() { return window->isOpen(); }
private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text tileRender;
    sf::Text playerRender;
	sf::Text zombieRender;
    Map map;
	Logger logger;
    Player player;
    int fontSize = 16;
	std::function<void()> updateOverride;
};