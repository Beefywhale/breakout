#pragma once
#include "../map/Tile.h"
#include <memory>

class Event {
public:
    Event() {}
    ~Event() {}
    Event(const Event&) {}

    struct CollisionEvent {
        std::shared_ptr<Tile> tile;
    
        CollisionEvent() {}
        ~CollisionEvent() {}
        CollisionEvent(const CollisionEvent&) {}
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