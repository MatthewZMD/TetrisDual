#include "concreteboard.h"
#include "cellstate.h"
#include "boardinfo.h"
#include <iostream>

ConcreteBoard::ConcreteBoard(int boardNum, std::string fileName, int l): boardNum { boardNum }, score{ 0 }, countTurn{ 0 }, boardInfo{} {
    level = std::shared_ptr<Level>(new Level0(fileName));
    while(l > 0){
        level = level->levelUp();
        --l;
    }
    allCells.clear();
    std::vector<Cell> temp;
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            Coordinate pos{i, j};
            temp.emplace_back(Cell(pos));
        }
        allCells.emplace_back(temp);
        temp.clear();
    }
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (i != 17) {
                allCells[i][j].attach(&(allCells[i + 1][j]));
            }
            if (i != 0) {
                allCells[i][j].attach(&(allCells[i - 1][j]));
            }
        }
    }

    nextType = level->genBlock();
    std::cout << "shawn nb" << std::endl;
    genThis();
    std::cout << "shawn sb" << std::endl;
}

void ConcreteBoard::levelUp(){
    level = level->levelUp();
    if (level->getLevel() == 3) {
        countTurn = 0;
    }
}

void ConcreteBoard::levelDown(){
    level = level->levelDown();
    if (level->getLevel() == 4) {
        countTurn = 0;
    }
}

void ConcreteBoard::right(int time){
    bool exist = false;
    while (time != 0){
        for (auto &i : thisBlock->cells){
            for (auto &j : thisBlock->cells){
                if (i->pos.col + 1 == j->pos.col){
                    exist = true;
                }
            }
            if (!exist){
                if (i->pos.col == 10 || !allCells[i->pos.row][i->pos.col + 1].isEmpty()){
                    break;
                }
            }
            exist = false;
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
    if (level->heavyOffset()){
        down();
    }
    notifyObservers();
}

void ConcreteBoard::left(int time){
    bool exist = false;
    while (time != 0){
        for (auto &i : thisBlock->cells){
            for (auto &j : thisBlock->cells){
                if (i->pos.col - 1 == j->pos.col){
                    exist = true;
                }
            }
            if (!exist){
                if (i->pos.col == 0 || !allCells[i->pos.row][i->pos.col - 1].isEmpty()){
                    break;
                }
            }
            exist = false;
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
    if (level->heavyOffset()){
        down();
    }
    notifyObservers();
}

void ConcreteBoard::rotate(bool isClockwise){
    int rmLength = 0;
    int newRow = 0;
    int newCol = 0;
    bool exist = false;
    if (isClockwise){
        for (auto &i : thisBlock->cells){
            if (rmLength < i->pos.col - thisBlock->btmLft.col){
                rmLength = i->pos.col - thisBlock->btmLft.col;
            }
        }
        for (auto &i : thisBlock->cells){
            newRow = thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col - rmLength;
            newCol = thisBlock->btmLft.col + thisBlock->btmLft.row - i->pos.row;
            for (auto &j : thisBlock->cells) {
                if (newRow == j->pos.row && newCol == j->pos.col) {
                    exist = true;
                }
            }
            if (!exist) {
                if (newCol > 10 || !allCells[newRow][newCol].isEmpty()) {
                    return;
                }
            }
            exist = false;
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
    } else {
        for (auto &i : thisBlock->cells){
            if (rmLength < thisBlock->btmLft.row - i->pos.row){
                rmLength = thisBlock->btmLft.row - i->pos.row;
            }
        }
        for (auto &i : thisBlock->cells){
            newRow = thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col;
            newCol = thisBlock->btmLft.col - thisBlock->btmLft.row + i->pos.row + rmLength;
            for (auto &j : thisBlock->cells) {
                if (newRow == j->pos.row && newCol == j->pos.col) {
                    exist = true;
                }
            }
            if (!exist) {
                if (newCol > 10 || !allCells[newRow][newCol].isEmpty()) {
                    return;
                }
            }
            exist = false;
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
    notifyObservers();
}

bool ConcreteBoard::down(){
    bool exist = false;
    for (auto &i : thisBlock->cells){
        for (auto &j : thisBlock->cells){
            if (i->pos.row + 1 == j->pos.col)
                {
                    exist = true;
                }
        }
        if (!exist){
            if (i->pos.row == 17 || !allCells[i->pos.row + 1][i->pos.col].isEmpty())
                {
                    return false;
                }
        }
        exist = false;
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
    notifyObservers();
    return true;
}


void ConcreteBoard::drop() {
	// down until impossible
	while (down());
    // Consider level4 case
	if (level->dropBrownBlock()) {
        if (countTurn == 5) {
			for (int i = 17; i >= 0; --i) {
				if (allCells[i][5].type == CellType::E) {
                    allCells[i][5].type = CellType::Star;
                }
            }
        } else {
			++countTurn;
		}
    }
	bool lineFull = 1;
	int RemoveLine = 0;
	for (int i = 17; i >= 0; --i) {
		for (int j = 0; j < 11; ++j) {
			if (allCells[i][j].isEmpty()) {
				lineFull = 0;
				break;
			}
		}
		if (lineFull == 1) {
			for (int j = 0; j < 11; ++j) {
				allCells[i][j].cellState.cellStatus = CellStatus::Dead;
				if (allCells[i][j].squad.size() == 0) {
					score += (allCells[i][j].blockLevel + 1) * (allCells[i][j].blockLevel + 1);
				}
				allCells[i][j].type = CellType::E;
				for (auto &k : allCells[i][j].squad) {
					for (unsigned p = 0; p < k->squad.size(); ++p) {
						if (k->squad[p]->pos == allCells[i][j].pos) {
							k->squad.erase(k->squad.begin() + p);
							break;
						}
					}
				}
				allCells[i][j].notifyObservers();
			}
			++RemoveLine;
			++i;
		}
		lineFull = 1;
	}
	if (RemoveLine != 0) {
		score += (RemoveLine + level->getLevel()) * (RemoveLine + level->getLevel());
	}
	for (int j = 0; j < 11; ++j) {
		if (!allCells[2][j].isEmpty()) {
			throw "Game Over";
		}
	}
	turnGG = true;
	notifyObservers();
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
        case CellType::Star:
            break;
        case CellType::E:
            break; // Do nothing
    }
    thisBlock = std::make_shared<Block>(nextType, level->getLevel(), cells);
    nextType = CellType::E;
}

CellType ConcreteBoard::genNext(){
    return level->genBlock();
}


std::shared_ptr<Board> ConcreteBoard::getBoard() {
    return shared_from_this();
}

int ConcreteBoard::getBoardNum() const {
    return boardNum;
}

void ConcreteBoard::setNext(CellType newNext) {
    nextType = newNext;
}

bool ConcreteBoard::isTurnOver() const {
	return turnGG;
}

Info& ConcreteBoard::getInfo()  {
       boardInfo.player = boardNum;
       boardInfo.level = level->getLevel();
       boardInfo.score = score;
       boardInfo.boardData = display();
       boardInfo.nextType = nextType;
       return boardInfo;
}

std::vector<std::vector<char>> ConcreteBoard::display() {
	std::vector<std::vector<char>> displayBoard;
	std::vector<char> temp;
	for (int i = 0; i < 18; ++i) {
		for (int j = 0; j < 11; ++j) {
			switch(allCells[i][j].type) {
				case CellType::I:
					temp.emplace_back('I');
					break;
				case CellType::J:
					temp.emplace_back('J');
					break;
				case CellType::L:
					temp.emplace_back('L');
					break;
				case CellType::O:
					temp.emplace_back('O');
					break;
				case CellType::S:
					temp.emplace_back('S');
					break;
				case CellType::Z:
					temp.emplace_back('Z');
					break;
				case CellType::T:
					temp.emplace_back('T');
					break;
				case CellType::E:
					temp.emplace_back(' ');
					break;
				case CellType::Star:
					temp.emplace_back('*');
					break;
			}
		}
		displayBoard.emplace_back(temp);
		temp.clear();
	}
        std::cout << "here" << std::endl;
	return displayBoard;
}
