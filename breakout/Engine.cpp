#include "Engine.h"

Engine::Engine(sf::RenderWindow* pWindow, Map pMap, Player pPlayer) {
    window = pWindow;
    map = pMap;
    player = pPlayer;

    if (!font.loadFromFile("font.ttf")) {
        // err here
    }

    window->setFramerateLimit(60);

    tileRender.setFont(font);
    tileRender.setCharacterSize(fontSize);
    playerRender.setFont(font);
    playerRender.setCharacterSize(fontSize);
}

void Engine::start() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::KeyReleased) {
				int keyCode = event.key.code;
                if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::W || keyCode == sf::Keyboard::S) {
					player.setWalk(true);
				} else if (keyCode == sf::Keyboard::Escape) {
					window->close();
				}
            }
        }

        window->clear();

		for (Tile i : map.getTiles()) {
			tileRender.setFillColor(i.getColor());

			if (player.distance(i.getPosition().x, i.getPosition().y, player.getPosition().x, player.getPosition().y) > player.getSight()) {
				tileRender.setFillColor(sf::Color(i.getColor().r - 150, i.getColor().g - 150, i.getColor().b - 150));
			}

			if (i.getPosition().x == player.getPosition().x && i.getPosition().y == player.getPosition().y) {
				continue;
			}

			tileRender.setString(i.getChar());
			tileRender.setPosition(i.getPosition().x * (fontSize - 2),
								   i.getPosition().y * (fontSize - 2)
									);

			window->draw(tileRender);
		}

		player.update(map);

		playerRender.setFillColor(player.getColor());
		playerRender.setString(player.getChar());
		playerRender.setPosition(player.getPosition().x * (fontSize - 2),
								 player.getPosition().y * (fontSize - 2)
								);

        window->draw(playerRender);

        window->display();
    }
}
