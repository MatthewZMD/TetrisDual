#include "cell.h"
#include "cellstate.h"
#include "info.h"
#include "cellinfo.h"

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

void Cell::notify(Subject & s) {
	if (s.getState().cellStatus == CellStatus::Restore) {
		if (s.getInfo().pos.row == pos.row - 1) {
			setState(CellState{CellStatus::Down});
			notifyObservers();
		}
	}
	else {
		if (s.getInfo().pos.row == pos.row + 1) {
			blockLevel = s.getInfo().blockLevel;
			type = s.getInfo().type;
			squad = s.getInfo().squad;

			// update squad
			for (cell : squad) {
				for (i = 0; i < cell->squad.size(); ++i) {
					if (cell->squad.at(i)->pos == s.pos) {
						cell->squad.at(i).pos = pos;
						break;
					}
				}
			}
		}
	}
}

bool Cell::isEmpty() const{
    return type == CellType::E;
}

CellInfo Cell:getInfo() const {
	return CellInfo{pos, blockLevel, type, squad};
}

CellState Cell::getState() const {
	return cellState;
}

void Cell::setState(CellState s) {
	cellState = s;
}
