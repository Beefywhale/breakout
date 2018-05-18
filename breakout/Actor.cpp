#include "Actor.h"

Actor::Actor() {
    pos.x = 0;
    pos.y = 0;
    ch = L'@';
}

Actor::Actor(int x, int y, wchar_t pCh, Color pColor) {
    pos.x = x;
    pos.y = y;
    ch = pCh;
    color = pColor;
}

void Actor::setPosition(int x, int y) {
    pos.x = x;
    pos.y = y;
    color = Color(255,255,255);
}

void Actor::move(int x, int y) {
    pos.x += x;
    pos.y += y;
}

int Actor::distance(int startX, int startY, int targetX, int targetY) {
	return sqrt(pow((targetX - startX), 2) + pow((targetY - startY), 2));
}
