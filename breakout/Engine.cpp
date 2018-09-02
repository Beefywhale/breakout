#include "Engine.hpp"

Engine::Engine(sf::RenderWindow* window, Map map) {
    m_window = window;
    m_map = map;
	fontSize = 16;
	sf::err().rdbuf(0);


    if (!font.loadFromFile("font.ttf")) {
		logger.error("Failed to load font!");
    }

    window->setFramerateLimit(60);

    tileRender.setFont(font);
    tileRender.setCharacterSize(fontSize);
    playerRender.setFont(font);
    playerRender.setCharacterSize(fontSize);

	logger.plaintext("______                _               _   \n| ___ \\              | |             | |  \n| |_/ /_ __ ___  __ _| | _____  _   _| |_ \n| ___ \\ '__/ _ \\/ _` | |/ / _ \\| | | | __|\n| |_/ / | |  __/ (_| |   < (_) | |_| | |_ \n\\____/|_|  \\___|\\__,_|_|\\_\\___/ \\__,_|\\__|\n");
}

void Engine::update(Player player) {
    m_window->clear();

    for (auto tilePair : m_map.getTiles()) {
        Tile i = tilePair.second;
	    tileRender.setFillColor(sf::Color(i.getColor().red, i.getColor().green, i.getColor().blue));

		//draw darker color
		if (player.distance(i.getPosition().x, i.getPosition().y, player.getPosition().x, player.getPosition().y) > player.sight()) {
			tileRender.setFillColor(sf::Color((i.getColor().red - 150)%150, (i.getColor().green - 150)%150, (i.getColor().blue - 150)%150));
		}

		if (i.getPosition().x == player.getPosition().x && i.getPosition().y == player.getPosition().y) {
			continue;
		}

		tileRender.setString(i.getChar());
		tileRender.setPosition(i.getPosition().x * (fontSize - 2),
							   i.getPosition().y * (fontSize - 2)
							  );

	    m_window->draw(tileRender);
	}

	playerRender.setFillColor(sf::Color(player.getColor().red, player.getColor().green, player.getColor().blue));
	playerRender.setString(player.getChar());
	playerRender.setPosition(player.getPosition().x * (fontSize - 2),
							 player.getPosition().y * (fontSize - 2)
							);

    m_window->draw(playerRender);

    m_window->display();
}


void Engine::changeFontSize(int newSize) {
	fontSize = newSize;
	tileRender.setCharacterSize(fontSize);
	playerRender.setCharacterSize(fontSize);
}
