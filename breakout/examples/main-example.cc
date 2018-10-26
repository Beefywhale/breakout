#include <SFML/Graphics.hpp>
#include "../global.hpp"
#include "../Engine.hpp"
#include "../map/Map.hpp"
#include "Player.hpp"
#include "../map/Item.hpp"

void events() {
    //loop over all queued events until queue is empty, may need to be async in future
    while (!eventHandler.isEmpty()) {
        eventHandler.pollEvents()(); // call the polled event
    }
}

// check for keyboard input and move the player accordingly, handle sfml window events
void input(Player& player, sf::RenderWindow& window, Map map) {
    if (window.hasFocus()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // player walk key checks
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.safeMove(-player.movementSpeed, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.safeMove(player.movementSpeed, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.safeMove(0, player.movementSpeed);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.safeMove(0, -player.movementSpeed);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "breakout"); // create an SFML RenderWindow

    Map map("maps/test.json"); // create the main Map object and load tiles from a json file
    Player player(0, 0, L'@', bt::Color(255, 255, 0), map); // create main Player object

    Engine engine(window, map); // create main Engine object with SFML window and map
    engine.addActor(player); // add main player to the engine for drawing

    while (engine.isRunning()) { // main game loop
        events();
        input(player, window, map);
        engine.draw();
    }
    return 0;
}
