#include <SFML/Graphics.hpp>
#include "../global.hpp"
#include "../Engine.hpp"
#include "../map/Map.hpp"
#include "Player.hpp"
#include "../map/Item.hpp"

void eventLoop() {
    while (!eventHandler.isEmpty()) {
        eventHandler.pollEvents()();
    }
}

// function to check for keyboard input and to move the player accordingly.
void inputLoop(Player* player, sf::RenderWindow* window, Map map) {
    if (window->hasFocus()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }
        //player walk loop
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player->safeMove(-player->movementSpeed, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player->safeMove(player->movementSpeed, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player->safeMove(0, player->movementSpeed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player->safeMove(0, -player->movementSpeed);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "breakout");

    Player player(0, 0, L'@', bt::Color(255, 255, 0));
    Map map;
    map.load("maps/test.json");
    player.setMap(map);

    Engine engine(&window, map);
    engine.addActor(&player);

    // example for printing player inventory with number of items with the name, EX: (2) Apple
    for (auto i : player.getInventory()->getItems()) {
        logger.info("(" + std::to_string(i.second.size()) + ") " + i.first);
    }

    while (engine.isRunning()) { //game loop
        eventLoop();
        inputLoop(&player, &window, map);
        player.update();
        engine.draw();
    }
    return 0;
}
