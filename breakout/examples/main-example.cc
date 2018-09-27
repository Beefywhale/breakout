#include <SFML/Graphics.hpp>
#include "../global.hpp"
#include "../Engine.hpp"
#include "../map/Map.hpp"
#include "../entities/Player.hpp"
#include "../Logger.hpp"
#include "../map/Item.hpp"
#include "../custom/Event.hpp"

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
                if (tileAt.type->door.open) {
                    tileAt.type->door.open = false;
                    tileAt.setSolid(true);
                } else {
                    tileAt.type->door.open = true;
                    tileAt.setSolid(false);
                }
            }
        } else if (event->type == Event::PlayerMove) {
            Tile tileAt = *event->playerMove->movedTile;
            int tileX = tileAt.getPosition().x;
            int tileY = tileAt.getPosition().y;
            Player* playerAt = *event->playerMove->player;
            int playerX = playerAt->getPosition().x;
            int playerY = playerAt->getPosition().y;
            logger.info("Player moved from: " + std::to_string(playerX) + std::string(",") + std::to_string(playerY) + " to: " + std::to_string(tileX) + std::string(",") + std::to_string(tileY) + "\n");
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
    map.load("maps/test.json");

    Engine engine(&window, map);

    // example for printing player inventory with number of items with the name, EX: (2) Apple
    for (auto i : player.getInventory()->getItems()) {
        logger.info("(" + std::to_string(i.second.size()) + ") " + i.first);
    }

    while (engine.isRunning()) { //game loop
        eventLoop();
        inputLoop(&player, &window, map);
        player.update();
        engine.update(player);
    }
    return 0;
}
