#include "Map.h"

Map::Map() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			Tile newTile(i, j, L'.', bt::Color(255, 255, 255), false);
			tileMap.insert(std::make_pair(std::make_pair(i, j), newTile));
		}
	}

	for (int x = 0; x < 15; x++) {
		Tile newTile(x, 15, L'#', bt::Color(255,255,255), true);
		newTile.setType(TM.getTypes().at("wall"));
		tileMap.insert(std::make_pair(std::make_pair(x, 15), newTile));
	}
}

Tile Map::getTileAt(int x, int y) {
    it = tileMap.find(std::make_pair(x, y));
    if (it != tileMap.end()) {
        return tileMap[std::make_pair(x, y)];
    } else {
        logger.warning("Out of Bounds, creating temporary invisible Tile!");
        return Tile(x, y, L'.', bt::Color(255, 255, 255), false);
    }
}
