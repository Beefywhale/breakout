#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "map/Tile.h"
#include "entities/Player.h"
#include "map/Type.h"
#include "map/Map.h"
#include "Logger.h"

/**
<<<<<<< HEAD
* @brief Engine.
=======
* @brief Engine class
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
*/
class Engine {
public:
    Engine() {}

   /**
	* Preload variables and objects.
	* @param pWindow A RenderWindow* to draw to.
	* @param pMap A Map to get the Tiles from.
<<<<<<< HEAD
=======
	* @param pPlayer A Player to draw and update.
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
	*/
	Engine(sf::RenderWindow* pWindow, Map pMap);
    
   /**
	* The game loop.
<<<<<<< HEAD
    * @param player The current player.
	*/
	void update(Player player);

=======
	*/
	void update(Player player);
    
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
   /**
	* Get the current Map.
	* @return the Engine's Map.
	*/
	Map getMap() { return map; }

   /**
	* Change the font rendering size.
	* @param newSize The new size to set the font to.
	*/
	void changeFontSize(int newSize);

<<<<<<< HEAD
   /**
    * Check if the Engine is still running.
    * @return A boolean which is true if the Engine is still running
    */
=======
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
	bool isRunning() { return window->isOpen(); }
private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text tileRender;
    sf::Text playerRender;
	sf::Text zombieRender;
    Map map;
	Logger logger;
    int fontSize = 16;
	std::function<void()> updateOverride;
};