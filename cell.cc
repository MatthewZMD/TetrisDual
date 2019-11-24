#include "cell.h"

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
