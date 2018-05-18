#include "Map.h"

Map::Map() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			Tile newTile(i, j, L'.', bt::Color(255, 255, 255), false);
			tileMap.push_back(newTile);
		}
	}

	for (int x = 0; x < 15; x++) {
		Tile newTile(x, 15, L'#', bt::Color(255,255,255), true);
		newTile.setType(TM.getTypes().at("wall"));
		tileMap.push_back(newTile);
	}
}

Tile Map::getTileAt(int x, int y) {
    // rework this to be faster with itr and find_if, possible I might need to use boost
    for (Tile i : tileMap) {
        if (i.getPosition().x == x && i.getPosition().y == y) {
            return i;
        }
    }
	logger.warning("Out of Bounds, creating temporary invisible Tile!");
	return Tile(x, y, L'.', bt::Color(255, 255, 255), false);
}
