#include "Tile.h"

Tile::Tile() {}

Tile::Tile(int x, int y, wchar_t pCh, BColor pColor, bool pSolid) {
    pos.x = x;
    pos.y = y;
    ch = pCh;
    color = pColor;
    solid = pSolid;
}

void Tile::setType(Type newType) {
	type = newType;
}