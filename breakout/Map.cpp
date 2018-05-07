#include "Map.h"

void wallCollide() { printf("Colliding with Wall"); }

Map::Map() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			Tile newTile(i, j, L'.', sf::Color::White, false);
			tileMap.push_back(newTile);
		}
	}

	Type wall("wall", wallCollide);

	for (int x = 0; x < 15; x++) {
		Tile newTile(x, 15, L'#', sf::Color::White, true);
		newTile.setType(wall);
		tileMap.push_back(newTile);
	}
}

Tile Map::getTileAt(int x, int y) {
    // rework this to be faster with itr and find_if, possible I might need to use boost
    bool found = false;
    for (Tile i : tileMap) {
        if (i.getPosition().x == x && i.getPosition().y == y) {
            return i;
            found = true;
        }
    }
    if (!found) {
		return Tile(x, y, L'.', sf::Color::White, false);
    }
}
