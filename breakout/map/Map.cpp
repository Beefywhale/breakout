#include "Map.h"

Map::Map() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			Tile newTile(i, j, L'.', bt::Color(255, 255, 255));
			tileMap.insert(std::make_pair(std::make_pair(newTile.getPosition().x, newTile.getPosition().y), newTile));
		}
	}

	for (int x = 0; x < 15; x++) {
		Tile newTile(x, 15, L'#', bt::Color(255,255,255));
		newTile.setSolid(true);
		newTile.type->type = Type::Wall;
		tileMap.insert(std::make_pair(std::make_pair(newTile.getPosition().x, newTile.getPosition().y), newTile));
	}

	for (int k = 0; k < 5; k++) {
		Tile newTile(15, k, L'#', bt::Color(255,255,255));
		newTile.setSolid(true);
		newTile.type->type = Type::Wall;
		tileMap.insert(std::make_pair(std::make_pair(newTile.getPosition().x, newTile.getPosition().y), newTile));
	}
	for (int k = 6; k < 16; k++) {
		Tile newTile(15, k, L'#', bt::Color(255,255,255));
		newTile.setSolid(true);
		newTile.type->type = Type::Wall;
		tileMap.insert(std::make_pair(std::make_pair(newTile.getPosition().x, newTile.getPosition().y), newTile));
	}

	Tile newTile(15, 5, 240, bt::Color(255,0,255));
	newTile.setSolid(true);
	newTile.type->type = Type::Door;
	tileMap.insert(std::make_pair(std::make_pair(newTile.getPosition().x, newTile.getPosition().y), newTile));
}

Tile Map::getTileAt(int x, int y) {
    it = tileMap.find(std::make_pair(x, y));
    if (it != tileMap.end()) {
        return tileMap[std::make_pair(x, y)];
    } else {
        logger.warning("Out of Bounds, creating temporary invisible Tile!");
        return Tile(x, y, L'.', bt::Color(255, 255, 255));
    }
}
