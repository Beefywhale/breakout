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
using json = nlohmann::json;

class Map {
public:
    Map() {}
    Map(std::string path);

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

    struct {
        struct {
            int x;
            int y;
        } spawnpoint;
    } mapData;
};