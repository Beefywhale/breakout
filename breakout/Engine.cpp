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
    actorRender.setFont(font);
    actorRender.setCharacterSize(fontSize);

	logger.plaintext("______                _               _   \n| ___ \\              | |             | |  \n| |_/ /_ __ ___  __ _| | _____  _   _| |_ \n| ___ \\ '__/ _ \\/ _` | |/ / _ \\| | | | __|\n| |_/ / | |  __/ (_| |   < (_) | |_| | |_ \n\\____/|_|  \\___|\\__,_|_|\\_\\___/ \\__,_|\\__|\n");
}

void Engine::draw() {
    m_window->clear();
	//loop over all actors and draw them
	for (auto actor : actors) {
		actor->update();
		actorRender.setFillColor(sf::Color(actor->getColor().red, actor->getColor().green, actor->getColor().blue));
		actorRender.setString(actor->getChar());
		actorRender.setPosition(actor->getPosition().x * (fontSize - 2),
								actor->getPosition().y * (fontSize - 2)
		);
		actorPos.push_back(std::make_pair(actor->getPosition().x, actor->getPosition().y));
		m_window->draw(actorRender);
	}

	//loop over all tiles and draw them
    for (auto tilePair : m_map.getTiles()) {
        Tile i = tilePair.second;
		tileRender.setFillColor(sf::Color(i.getColor().red, i.getColor().green, i.getColor().blue));

		tileRender.setString(i.getChar());
		tileRender.setPosition(i.getPosition().x * (fontSize - 2),
							i.getPosition().y * (fontSize - 2)
							);

		it = std::find(actorPos.begin(), actorPos.end(), std::make_pair(i.getPosition().x, i.getPosition().y));
    	if (it == actorPos.end()) {
			m_window->draw(tileRender);
		}
	}

    m_window->display();
	actorPos.clear();
}


void Engine::changeFontSize(int newSize) {
	fontSize = newSize;
	tileRender.setCharacterSize(fontSize);
	actorRender.setCharacterSize(fontSize);
}

void Engine::addActor(Actor* actor) {
	actors.push_back(actor);
}
