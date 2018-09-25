#pragma once
#include <SFML/Graphics.hpp>
#include "../entities/Actor.hpp"
#include "Type.hpp"
using namespace bt;

class Tile: public Actor {
public:
    Tile() {}

	virtual ~Tile() {}

	Tile(int x, int y, wchar_t ch, Color color);

	bool solid() { return m_solid; }

	void setSolid(bool solid);

	Type* type;

private:
	bool m_solid;
};
