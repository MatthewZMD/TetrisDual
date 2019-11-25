#include "board.h"

void Board::levelUp(){
    
}

void Board::genThis() {
    std::vector<std::shared_ptr<Cell>> cells;
    Coordinate btmLft{3, 0};
    switch(nextType){
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
    thisBlock = std::shared_ptr<Block>(new Block{nextType, level->getLevel(), cells});
    nextType = CellType::E;
}

void Board::genNext() {
    nextType = level->genBlock();
}
