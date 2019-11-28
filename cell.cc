#include "cell.h"
#include "cellstate.h"
#include "info.h"
#include "cellinfo.h"

Cell::Cell(Coordinate pos): pos { pos }, cellState { CellState{CellStatus::Alive} }, cellInfo { CellInfo{pos, 0, CellType::E, std::vector<Cell*>{}} } {}

void Cell::restore() {
    blockLevel = 0;
    type = CellType::E;
    squad.clear();
}

void Cell::set(CellType t, int bl, std::vector<Cell*> s) {
    type = t;
    bl = blockLevel;
    squad = s;
}

void Cell::notify(Subject& s) {
    Cell& c = dynamic_cast<Cell&>(s);
	if (c.cellState.cellStatus == CellStatus::Dead) {
		if (c.cellInfo.pos.row == pos.row - 1) {
			c.cellState = CellState{CellStatus::Down};
			notifyObservers();
		}
	}
	else {
		if (c.cellInfo.pos.row == pos.row + 1) {
			blockLevel = c.cellInfo.blockLevel;
			type = c.cellInfo.type;
			squad = c.cellInfo.squad;

			// update squad
			for (auto& cell : squad) {
				for (unsigned i = 0; i < cell->squad.size(); ++i) {
					if (cell->squad.at(i)->pos == c.pos) {
						cell->squad.at(i)->pos = pos;
						break;
					}
				}
			}
		} else {
			c.cellState = CellState{CellStatus::Down};
			notifyObservers();
		}
	}
}

bool Cell::isEmpty() const{
    return type == CellType::E;
}

Info& Cell::getInfo() {
	cellInfo.pos = pos;
	cellInfo.blockLevel = blockLevel;
	cellInfo.type = type;
	cellInfo.squad = squad;
	return cellInfo;
}

State& Cell::getState(){
    return cellState;
}
