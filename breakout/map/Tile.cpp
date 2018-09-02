#include "Tile.hpp"

Tile::Tile(int x, int y, wchar_t ch, Color color) : Actor(x, y, ch, color) {
    m_solid = false;
    type = new Type();
    //type->type = Type::Floor;
}

void Tile::setSolid(bool solid) {
    m_solid = solid;
}
