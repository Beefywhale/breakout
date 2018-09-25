#pragma once
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "../libs/json.hpp"
#include <SFML/Graphics.hpp>
#include "../global.hpp"
#include "Tile.hpp"
#include "../Logger.hpp"
using json = nlohmann::json;

class Map {
public:
    Map() {};

    std::map<std::pair<int, int>, Tile> getTiles() { return tileMap; }

    Tile getTileAt(int x, int y);

    void load(const std::string path);
    void save(const std::string path);

private:
    std::map<std::pair<int, int>, Tile> tileMap;
    std::map<std::pair<int, int>, Tile>::iterator it;

    Logger logger;

    std::string m_path;

    json data;

    std::map<std::string, Type::Types> string2Type {
        std::make_pair("floor", Type::Floor),
		std::make_pair("door", Type::Door),
		std::make_pair("wall", Type::Wall)
	};

    std::map<Type::Types, std::string> type2String {
        std::make_pair(Type::Floor, "floor"),
		std::make_pair(Type::Door, "door"),
		std::make_pair(Type::Wall, "wall")
	};

    struct {
        struct {
            int x;
            int y;
        } spawnpoint;
    } mapData;
};
