#pragma once

class Type {
public:
    struct DoorType {
        bool open;
    };

    struct FloorType {};
    struct WallType {};

    Type() {}

    enum Types {
        Door,
        Floor,
        Wall,

        Count
    };

    Types type = Floor;

    union {
        DoorType door;
        FloorType floor;
        WallType wall;
    };

};
