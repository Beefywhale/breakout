#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "map/Tile.hpp"
#include "entities/Player.hpp"
#include "map/Map.hpp"
#include "Logger.hpp"

// Class: Engine
// A class for handling drawing and putting classes together.
class Engine {
public:
    // Group: Functions

	// Constructor: Engine
	// Default constructor.
    Engine() {}

	/* Constructor: Engine
	   Init variables and objects.

	   Parameters:
	      window - The SFML window to draw to.
		  map - The current <Map>.
	*/
	Engine(sf::RenderWindow* window, Map map);


	/* Function: update
       The main game loop, called every frame.
       Used to update positions and draw tiles.

       Parameters:
          player - The <Player> to draw.
	*/
	void update(Player player);

    /* Function: getMap
	   get the Engine <Map>.

	   Returns:
	      The Engine <Map>.
	*/
	Map getMap() { return m_map; }

	/* Function: changeFontSize
	   change the size of the Engine font.

	   Parameters:
	      newSize - the new size to make the font.
	*/
	void changeFontSize(int newSize);

    /* Function: isRunning
	   Check if Engine is running.

	   Returns:
	      A boolean which is true if Engine is running.
    */
	bool isRunning() { return m_window->isOpen(); }
private:
	// Group: Private Variables

	// Variable: m_window
	// The SFML window Engine draws to.
    sf::RenderWindow* m_window;

	// Variable: font
	// The font Engine uses to display text.
    sf::Font font;

	// Variable: tileRender
    sf::Text tileRender;

	// Variable: playerRender
    sf::Text playerRender;

	// Variable: m_map
	// The <Map> Engine gets the <Tile>s from.
    Map m_map;

	Logger logger;
    int fontSize;
};
