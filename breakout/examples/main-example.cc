#include <SFML/Graphics.hpp>
#include "../global.hpp"
#include "../Engine.hpp"
#include "../map/Map.hpp"
#include "../entities/Player.hpp"
#include "../Logger.hpp"
#include "../map/Item.hpp"
#include "../custom/Event.hpp"

#include <iostream>

void eventLoop(Player player, Map map) {
    while (!eventHandler.isEmpty()) {
        Event* event = eventHandler.pollEvents();
        event->emit(player, map);
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
            else if (event.type == sf::Event::KeyReleased) {
                int keyCode = event.key.code;
                if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::W || keyCode == sf::Keyboard::S) {
                    player->setWalk(true);
                }
            }
        }
        //player walk loop
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player->safeMove(-player->movementSpeed, 0, map);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player->safeMove(player->movementSpeed, 0, map);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player->safeMove(0, player->movementSpeed, map);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player->safeMove(0, -player->movementSpeed, map);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "breakout");

    Player player(0, 0, L'@', bt::Color(255, 255, 0));
    Map map;
    map.load("maps/test.json");

    Engine engine(&window, map);


    Item newItem;
    player.getInventory()->addItem(newItem);

    // example for printing player inventory with number of items with the name, EX: (2) Apple
    for (auto i : player.getInventory()->getItems()) {
        logger.info("(" + std::to_string(i.second.size()) + ") " + i.first);
    }

    while (engine.isRunning()) { //game loop
        eventLoop(player, map);
        inputLoop(&player, &window, map);
        player.update();
        engine.update(player);
    }
    return 0;
}
