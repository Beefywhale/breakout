#include "Map.hpp"

Map::Map(std::string path) {
	load(path);
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

void Map::load(const std::string path) {
	m_path = path;
	std::ifstream i(path);
	i >> data;

	int spawnX = data["Spawnpoint"]["x"];
	int spawnY = data["Spawnpoint"]["y"];

	mapData.spawnpoint.x = spawnX;
	mapData.spawnpoint.y = spawnY;

	for (auto i : data["Tiles"]) {
		if (i.find("x") == i.end()|| i.find("y") == i.end()) {
			logger.warning("Skipping over tile, missing coordinate entries.");
			continue;
		}

		Tile newTile(i["x"], i["y"], (wchar_t)i["char"], bt::Color(i["color"][0], i["color"][1], i["color"][2]));

		if (i.find("solid") == i.end()) {
			logger.warning("Tile at " + std::to_string(i["x"].get<int>()) + ", " + std::to_string(i["y"].get<int>()) + " missing 'solid' entry, using defaults.");
			newTile.setSolid(false);
		} else {
			newTile.setSolid(i["solid"]);
		}
		if (i.find("type") == i.end()) {
			logger.warning("Tile at " + std::to_string(i["x"].get<int>()) + ", " + std::to_string(i["y"].get<int>()) + " missing 'type' entry, using defaults.");
		} else {
			newTile.type = i["type"];
		}
		tileMap.insert(std::make_pair(std::make_pair(newTile.getPosition().x, newTile.getPosition().y), newTile));
	}

	if (data.find("Player") == data.end()) {
		//do stuff
	} else {

	}
}

void Map::save(const std::string path) {
	logger.info("Saving map to " + path);
	json tileData;
	tileData["Tiles"] = {};
	for (auto i : tileMap) {
		Tile tile = i.second;
		json tileObject;
		tileObject["x"] = tile.getPosition().x;
		tileObject["y"] = tile.getPosition().y;
		tileObject["solid"] = tile.solid();
		tileObject["type"] = tile.type;
		tileObject["char"] = (int) tile.getChar();
		tileObject["color"] = {tile.getColor().red, tile.getColor().green, tile.getColor().blue};

		tileData["Tiles"].push_back(tileObject);
		tileData["Spawnpoint"] = {{"x", mapData.spawnpoint.x}, {"y", mapData.spawnpoint.y}};
	}
	std::ofstream o(path);
	o << std::setw(4) << tileData << std::endl;

}
