#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "../custom/Color.hpp"
using namespace bt;

struct position {
	int x;
	int y;
};

class Actor {
public:
    Actor() {}
    Actor(int x, int y, wchar_t ch, Color color);
	virtual ~Actor() {};

	position getPosition() { return pos; }

    wchar_t getChar() { return m_ch; }

	Color getColor() { return m_color; }

	virtual void update() {}

	int distance(int startX, int startY, int targetX, int targetY);
	int sight() { return m_radius; }

    void move(int x, int y);
    void setPosition(int x, int y);
	void setSightRadius(int radius);

	position prevPos;
private:
    wchar_t m_ch;

    Color m_color;

	int m_radius = 3;

protected:
    position pos;
};
