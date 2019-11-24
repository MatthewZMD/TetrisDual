enum Status{
    AllDead, MeDead, Alive
};

enum CellType {
    I, J, L, O, S, Z, T, E
};

enum Direction {
    Top, Right, Nil, Left, Bottom
};

struct State {
    Direction direction;
    Status status;
};
