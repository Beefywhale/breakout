# breakout
WIP rouglike game framework using SFML.

# WIP
Seriously this is a Work in Progress, so you're free to use it but it's missing ALOT and it's limited in use.
If you want to see it's current state look <a href="https://github.com/Beefywhale/breakout/releases">here</a>.

# Requirements
* SFML 2.4.2.

# Usage
Documentation <a href="http://beefywhale.tk/breakout/documentation/html/annotated.html">here</a>

```cpp
#include <SFML/Graphics.hpp>
#include "breakout/Engine.h"
#include "breakout/Map.h"
#include "breakout/entities/Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "breakout");

    Player player(0, 0, L'@', sf::Color(255,255,0));
    Map map;
    Engine engine(&window, map, player);
    engine.start();


    return 0;
}
```
Put this in a file named main.cpp and build it with SFML as a dependency. You'll need to copy the `font.ttf` to where you built the executable.
