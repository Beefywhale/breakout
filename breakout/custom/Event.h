#pragma once
#include "../map/Tile.h"
#include <memory>

class Event {
public:
    Event() {}

    struct CollisionEvent {
        std::shared_ptr<Tile> tile;
    };

    enum EventType {
        Collision,
        
        Count
    };

    EventType type;

    union {
        CollisionEvent* collision = new CollisionEvent();
    };
};