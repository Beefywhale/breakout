#pragma once
#include "../map/Tile.h"
#include <memory>

// Class: Event
// A class for handling events.
class Event {
public:
    /* Struct: CollisionEvent
       An event triggered on collisions with <Tile>s.

       Fields:
          tile - An std::shared_ptr<Tile> that was collided with.
    */
    struct CollisionEvent {
        std::shared_ptr<Tile> tile;
    };

    // Group: Functions

    // Constructor: Event
    // Default constructor.
    Event() {}

    //? Should I document this?
    enum EventType {
        Collision,
        
        Count
    };

    //? Should I document this?
    union {
        CollisionEvent* collision = new CollisionEvent();
    };

    // Group: Variables

    // Variable: type
    // The event type.
    EventType type;
};