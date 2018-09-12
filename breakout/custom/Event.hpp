#pragma once

#include "../map/Tile.hpp"
#include <memory>
class Player;

class Event {
public:
    /* Struct: Event::CollisionEvent
       An event triggered on collisions with <Tile>s.

       Fields:
          tile - An std::shared_ptr<Tile> that was collided with.
    */
    struct CollisionEvent {
        std::shared_ptr<Tile> tile;
    };

    struct PlayerMoveEvent {
        std::shared_ptr<Player*> player;
        std::shared_ptr<Tile> movedTile;
    };

    // Class: Event
    // A class for handling events.

    // Group: Functions

    // Constructor: Event
    // Default constructor.
    Event() {};

    //? Should I document this?
    enum EventType {
        Collision,
        PlayerMove,

        Count
    };

    //? Should I document this?
    CollisionEvent* collision = new CollisionEvent();
    PlayerMoveEvent* playerMove = new PlayerMoveEvent();

    // Group: Variables

    // Variable: Event
    // The event type.
    EventType type;
};
