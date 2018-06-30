#include <SFML/Graphics.hpp>
#include "../global.h"
#include "../Engine.h"
#include "../map/Map.h"
#include "../entities/Player.h"
#include "../Logger.h"
#include "../map/Item.h"
#include "../custom/Event.h"

#include <iostream>

void eventLoop() {
    while (!eventHandler.isEmpty()) {
        Event* event = eventHandler.pollEvents();
        if (event->type == Event::Collision) {
            Tile tileAt = *event->collision->tile;
            int tileX = tileAt.getPosition().x;
            int tileY = tileAt.getPosition().y;
            logger.info(std::string("Colliding with tile at: ") + std::to_string(tileX) + std::string(", ") + std::to_string(tileY) + "\n");
            if (tileAt.type->type == Type::Door) {
                logger.info("Colliding with a door");
            }
        }
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
    Engine engine(&window, map);

    // example for printing player inventory with number of items with the name, EX: (2) Apple
    for (auto i : player.getInventory()->getItems()) {
        logger.info("(" + std::to_string(i.second.size()) + ") " + i.first);
    }

    while (engine.isRunning()) { //game loop
        
        inputLoop(&player, &window, map);
        player.update();
        engine.update(player);
        eventLoop();
    }
    return 0;
}
