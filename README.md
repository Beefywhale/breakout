# breakout
WIP rouglike game framework using SFML.

# WIP
Seriously this is a Work in Progress, so you're free to use it but it's missing ALOT and it's limited in use.
If you want to see it's current state look <a href="https://github.com/Beefywhale/breakout/releases">here</a>.

# Requirements
* SFML 2.5.0

# Usage
~~Documentation <a href="http://beefywhale.tk/breakout/documentation/html/annotated.html">here</a>~~

```cpp
#include <SFML/Graphics.hpp>
#include "breakout/global.h"
#include "breakout/Engine.h"
#include "breakout/Map.h"
#include "breakout/entities/Player.h"
#include "breakout/Logger.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "breakout");
    Logger logger;

    //define types here; eventually will overhaul this...
    Type wall("wall");
    wall.setCollide([] { printf("colliding with wall type\n"); });
    TM.addType(wall);

    Player player(0, 0, L'@', BColor(255,255,0));
    Map map;
    Engine engine(&window, map, player);

	while (engine.isRunning()) { //game loop
		engine.update();
    }
    return 0;
}
```
Put this in a file named main.cpp and build it with SFML as a dependency. You'll need to copy the `font.ttf` to where you built the executable.
