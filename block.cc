#include "block.h"

void Block::recaliBtmLft(){
    Coordinate newBtmLft = Coordinate{200, 0};
    Coordinate cellPos;
    for(int i = 0; i < cells.size(); ++i) {
        cellPos = cells.at(i)->pos;
        if(cellPos.col < newBtmLft.col) newBtmLft.col = cellPos.col;
        if(cellPos.row > newBtmLft.row) newBtmLft.row = cellPos.row;
    }
    btmLft = newBtmLft;
}

Block::Block(CellType t, std::vector<std::vector<std::shared_ptr<Cell>>> allCells): btmLft { Coordinate{3, 0} } {
    switch(t){
        case CellType::I:
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 2));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 3));
            break;
        case CellType::J:
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 2));
            break;
        case CellType::L:
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 2));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col + 2));
            break;
        case CellType::O:
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 1));
            break;
        case CellType::S:
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col + 2));
            break;
        case CellType::Z:
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 2));
            break;
        case CellType::T:
            cells.emplace_back(allCells.at(btmLft.row).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col + 1));
            cells.emplace_back(allCells.at(btmLft.row - 1).at(btmLft.col + 2));
            break;
        case CellType::E:
            break; // Do nothing
    }
}
