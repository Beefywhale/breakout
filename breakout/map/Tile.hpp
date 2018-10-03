#pragma once
#include <SFML/Graphics.hpp>
#include "../entities/Actor.hpp"
using namespace bt;

class Tile: public Actor {
public:
    Tile() {}
	Tile(int x, int y, wchar_t ch, Color color);
	virtual ~Tile() {}

	bool solid() { return m_solid; }
	void setSolid(bool solid);

    std::string type;

private:
	bool m_solid;
};
