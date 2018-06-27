#pragma once
#include <SFML/Graphics.hpp>
#include "../entities/Actor.h"
using namespace bt;

/**
* @brief Tile.
*/
class Tile: public Actor {
public:
    Tile() {}
	virtual ~Tile() {}

   /**
	* Create a new Tile at an x and y position, with text and a color.
	* @param x Tile's starting x position.
	* @param y Tile's starting y position.
	* @param ch Tile's text representing it in-game.
	* @param color Color of the Tile's text.
	*/
	Tile(int x, int y, wchar_t ch, Color color);

	bool solid() { return m_solid; }

	void setType(std::string type);
	void setSolid(bool solid);
private:
    bool m_solid;
	std::string m_type;
};
