#include "Tile.h"

Tile::Tile() {}

Tile::Tile(int x, int y, wchar_t pCh, sf::Color pColor, bool pSolid) {
    pos.x = x;
    pos.y = y;
    ch = pCh;
    color = pColor;
    solid = pSolid;
}
