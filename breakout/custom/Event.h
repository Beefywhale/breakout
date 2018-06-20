#pragma once
#include "../map/Tile.h"

class Event {
public:
    Event() {}
    ~Event() {}
    Event(const Event&) {}

    struct CollisionEvent {
        Tile tile;
    
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
        CollisionEvent collision;
    };
};