#pragma once

#include "../map/Tile.hpp"
#include <memory>
class Player;

class Event {
public:
    struct CollisionEvent {
        std::shared_ptr<Tile> tile;
    };

    struct PlayerMoveEvent {
        std::shared_ptr<Player*> player;
        std::shared_ptr<Tile> movedTile;
    };

    Event() {};

    enum EventType {
        Collision,
        PlayerMove,

        Count
    };

    CollisionEvent* collision = new CollisionEvent();
    PlayerMoveEvent* playerMove = new PlayerMoveEvent();

    EventType type;
};
