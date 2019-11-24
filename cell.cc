#include "cell.h"

Cell::Cell(Coordinate pos): pos { pos } {}

void Cell::restore() {
    blockLevel = 0;
    type = CellType::E;
    squad = nullptr;
}

void Cell::set(CellType t, int bl, Coordinate** s) {
    type = t;
    bl = blockLevel;
    squad = s;
}
