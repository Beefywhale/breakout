# breakout
WIP rouglike game framework using SFML.

# WIP
Seriously this is a Work in Progress, so you're free to use it but it's missing ALOT and it's limited in use.
If you want to see it's current state look <a href="https://github.com/Beefywhale/breakout/releases">here</a>.

# Requirements
* SFML 2.5.0

# Usage
Documentation <a href="http://beefywhale.tk/breakout/documentation/html/annotated.html">here</a>

```cpp
#include <SFML/Graphics.hpp>
#include "breakout/global.h"
#include "breakout/Engine.h"
#include "breakout/map/Map.h"
#include "breakout/entities/Player.h"
#include "breakout/Logger.h"

void playerInput(Player* player, Map map) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player->safeMove(-player->movementSpeed, 0, map);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player->safeMove(player->movementSpeed, 0, map);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player->safeMove(0, player->movementSpeed, map);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player->safeMove(0, -player->movementSpeed, map);
    }
}

void types() {
    Type wall("wall");
    wall.setCollide([] { printf("colliding with wall type\n"); });
    TM.addType(wall);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "breakout");
    Logger logger;

    types();

    Player player(0, 0, L'@', bt::Color(255,255,0));
    Map map;
    Engine engine(&window, map);

	while (engine.isRunning()) {p
            sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {
                int keyCode = event.key.code;
                if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::W || keyCode == sf::Keyboard::S) {
                    player.setWalk(true);
                }
            }
        }

        playerInput(&player, map);
        player.update();
		engine.update(player);
    }
    return 0;
}

```
Put this in a file named main.cpp and build it with SFML as a dependency. You'll need to copy the `font.ttf` to where you built the executable.
