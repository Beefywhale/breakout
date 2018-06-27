#include "Actor.h"

Actor::Actor(int x, int y, wchar_t ch, Color color) {
    pos.x = x;
    pos.y = y;
    m_ch = ch;
    m_color = color;
}

void Actor::move(int x, int y) {
    pos.x += x;
    pos.y += y;
}

int Actor::distance(int startX, int startY, int targetX, int targetY) {
	return static_cast<int>(sqrt(pow((targetX - startX), 2) + pow((targetY - startY), 2)));
}

void Actor::setPosition(int x, int y) {
    pos.x = x;
    pos.y = y;
    m_color = Color(255,255,255);
}

void Actor::setSightRadius(int radius) {
    m_radius = radius;
}