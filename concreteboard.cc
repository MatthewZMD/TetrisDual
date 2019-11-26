#include "concreteboard.h"

void ConcreteBoard::levelUp(){
    level = level->levelUp();
}

void ConcreteBoard::levelDown(){
    level = level->levelDown();
}

void ConcreteBoard::right(int time){
    bool exist = 0;
    while (time != 0){
        for (auto &i : thisBlock->cells){
            for (auto &j : thisBlock->cells){
                if (i->pos.col + 1 == j->pos.col){
                    exist = 1;
                }
            }
            if (exist == 0){
                if (i->pos.col == 10 || !allCells[i->pos.row][i->pos.col + 1].isEmpty()){
                    break;
                }
            }
            exist = 0;
        }
        CellType curType = thisBlock->cells[0]->type;
        int curLevel = thisBlock->cells[0]->blockLevel;
        std::vector<std::shared_ptr<Cell>> temp;
        for (auto &i : thisBlock->cells){
            temp.emplace_back(&(allCells[i->pos.row][i->pos.col + 1]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{curType, curLevel, temp});
        thisBlock->recaliBtmLft();
        --time;
    }
    if (level->getLevel() == 3){
        down();
    }
}

void ConcreteBoard::left(int time){
    bool exist = 0;
    while (time != 0){
        for (auto &i : thisBlock->cells){
            for (auto &j : thisBlock->cells){
                if (i->pos.col - 1 == j->pos.col){
                    exist = 1;
                }
            }
            if (exist == 0){
                if (i->pos.col == 0 || !allCells[i->pos.row][i->pos.col - 1].isEmpty()){
                    break;
                }
            }
            exist = 0;
        }
        CellType curType = thisBlock->cells[0]->type;
        int curLevel = thisBlock->cells[0]->blockLevel;
        std::vector<std::shared_ptr<Cell>> temp;
        for (auto &i : thisBlock->cells){
            temp.emplace_back(&(allCells[i->pos.row][i->pos.col - 1]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{curType, curLevel, temp});
        thisBlock->recaliBtmLft();
        --time;
    }
    if (level->getLevel() == 3){
        down();
    }
}

void ConcreteBoard::rotate(bool isClockwise){
    int rmLength = 0;
    int newRow = 0;
    int newCol = 0;
    bool exist = 0;
    if (isClockwise == 1){
        for (auto &i : thisBlock->cells){
            if (rmLength < i->pos.col - thisBlock->btmLft.col){
                rmLength = i->pos.col - thisBlock->btmLft.col;
            }
        }
        for (auto &i : thisBlock->cells){
            int newRow = thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col - rmLength;
            int newCol = thisBlock->btmLft.col + thisBlock->btmLft.row - i->pos.row;
            for (auto &j : thisBlock->cells) {
                if (newRow == j->pos.row && newCol == j->pos.col) {
                    exist = 1;
                }
            }
            if (exist = 0) {
                if (newCol > 10 || !allCells[newRow][newCol].isEmpty()) {
                    return;
                }
            }
            exist = 0;
        }
        CellType curType = thisBlock->cells[0]->type;
        int curLevel = thisBlock->cells[0]->blockLevel;
        std::vector<std::shared_ptr<Cell>> temp;
        for (auto &i : thisBlock->cells){
            temp.emplace_back(&(allCells[thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col - rmLength][thisBlock->btmLft.col + thisBlock->btmLft.row - i->pos.row]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{curType, curLevel, temp});
        thisBlock->recaliBtmLft();
    }else{
        for (auto &i : thisBlock->cells){
            if (rmLength < thisBlock->btmLft.row - i->pos.row){
                rmLength = thisBlock->btmLft.row - i->pos.row;
            }
        }
        for (auto &i : thisBlock->cells){
            int newRow = thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col;
            int newCol = thisBlock->btmLft.col - thisBlock->btmLft.row + i->pos.row + rmLength;
            for (auto &j : thisBlock->cells) {
                if (newRow == j->pos.row && newCol == j->pos.col) {
                    exist = 1;
                }
            }
            if (exist = 0) {
                if (newCol > 10 || !allCells[newRow][newCol].isEmpty()) {
                    return;
                }
            }
            exist = 0;
        }
        CellType curType = thisBlock->cells[0]->type;
        int curLevel = thisBlock->cells[0]->blockLevel;
        std::vector<std::shared_ptr<Cell>> temp;
        for (auto &i : thisBlock->cells){
            temp.emplace_back(&(allCells[thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col][thisBlock->btmLft.col - thisBlock->btmLft.row + i->pos.row + rmLength]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{curType, curLevel, temp});
        thisBlock->recaliBtmLft();
    }
}

bool ConcreteBoard::down(){
    bool exist = 0;
    for (auto &i : thisBlock->cells){
        for (auto &j : thisBlock->cells){
            if (i->pos.row + 1 == j->pos.col)
                {
                    exist = 1;
                }
        }
        if (exist == 0){
            if (i->pos.row == 17 || !allCells[i->pos.row + 1][i->pos.col].isEmpty())
                {
                    return false;
                }
        }
        exist = 0;
    }
    CellType curType = thisBlock->cells[0]->type;
    int curLevel = thisBlock->cells[0]->blockLevel;
    std::vector<std::shared_ptr<Cell>> temp;
    for (auto &i : thisBlock->cells){
        temp.emplace_back(&(allCells[i->pos.row + 1][i->pos.col]));
        i->restore();
    }
    thisBlock = std::shared_ptr<Block>(new Block{curType, curLevel, temp});
    thisBlock->recaliBtmLft();
    return true;
}

void ConcreteBoard::genThis(){
    std::vector<std::shared_ptr<Cell>> cells;
    Coordinate btmLft{3, 0};
    switch (nextType){
        case CellType::I:
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 2)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 3)));
            break;
        case CellType::J:
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 2)));
            break;
        case CellType::L:
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 2)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 2)));
            break;
        case CellType::O:
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
            break;
        case CellType::S:
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 2)));
            break;
        case CellType::Z:
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 2)));
            break;
        case CellType::T:
            cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 1)));
            cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 2)));
            break;
        case CellType::E:
            break; // Do nothing
    }
    thisBlock = std::shared_ptr<Block>(new Block{nextType, level->getLevel(), cells});
    nextType = CellType::E;
}

void ConcreteBoard::genNext(){
    nextType = level->genBlock();
}
