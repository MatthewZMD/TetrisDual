#include "cell.h"

Cell::Cell(Coordinate pos): cellInfo { CellInfo{pos, 0, CellType::E, std::vector<Cell*>{}} },
                            pos { pos }, blockLevel { 0 }, type { CellType::E }, cellState { CellState{CellStatus::Alive} } {}

void Cell::restore() {
    blockLevel = 0;
    type = CellType::E;
    squad.clear();
}

void Cell::set(CellType t, int bl, std::vector<Cell*> s) {
    type = t;
    blockLevel = bl;
    squad = s;
}

void Cell::notify(Subject& s) {
    Cell & c = dynamic_cast<Cell&>(s);
    CellInfo & info = dynamic_cast<CellInfo&>(c.getInfo());

	if (c.cellState.cellStatus == CellStatus::Dead) {
		if (info.pos.row == pos.row + 1) {
			c.cellState = CellState{CellStatus::Down};
			notifyObservers();
		}
	}
	else {
		if (info.pos.row == pos.row - 1) {
			blockLevel = info.blockLevel;
			type = info.type;
			squad = info.squad;

			// update squad
			for (auto& cell : squad) {
				for (unsigned i = 0; i < cell->squad.size(); ++i) {
					if (cell->squad.at(i)->pos == c.pos) {
						cell->squad.at(i) = this;
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
