#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "map/Tile.hpp"
#include "entities/Actor.hpp"
#include "map/Map.hpp"
#include "custom/Logger.hpp"

class Engine {
public:
    Engine() {}
	Engine(sf::RenderWindow& window, Map map);

	void draw();
	void changeFontSize(int newSize);
	void addActor(Actor& actor);

	Map getMap() { return m_map; }

	bool isRunning() { return m_window->isOpen(); }
private:
    sf::RenderWindow* m_window;
    sf::Font font;
    sf::Text tileRender;
    sf::Text actorRender;

	std::vector<Actor*> actors;
	std::vector<std::pair<int, int>> actorPos;
	std::vector<std::pair<int, int>>::iterator it;

	Map m_map;
	Logger logger;
    int fontSize;
};
