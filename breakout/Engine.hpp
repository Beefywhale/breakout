#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "map/Tile.hpp"
#include "entities/Player.hpp"
#include "map/Map.hpp"
#include "Logger.hpp"

class Engine {
public:
    Engine() {}
	Engine(sf::RenderWindow* window, Map map);

	void update(Player player);
	void changeFontSize(int newSize);

	Map getMap() { return m_map; }

	bool isRunning() { return m_window->isOpen(); }
private:
    sf::RenderWindow* m_window;
    sf::Font font;
    sf::Text tileRender;
    sf::Text playerRender;

	Map m_map;

	Logger logger;
    int fontSize;
};
