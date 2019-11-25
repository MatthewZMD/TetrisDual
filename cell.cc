#include "cell.h"

Cell::Cell(Coordinate pos): pos { pos } {}

void Cell::restore() {
    blockLevel = 0;
    type = CellType::E;
    squad.clear(); 
}

void Cell::set(CellType t, int bl, std::vector<Coordinate> s) {
    type = t;
    bl = blockLevel;
    squad = s;
}

bool Cell::isEmpty() const{
    return type == CellType::E;
}
