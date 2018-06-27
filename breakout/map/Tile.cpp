#include "Tile.h"

Tile::Tile(int x, int y, wchar_t ch, Color color) : Actor(x, y, ch, color) {
    m_solid = false;
}

void Tile::setType(std::string type) {
    m_type = type;
}

void Tile::setSolid(bool solid) {
    m_solid = solid;
}