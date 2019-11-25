#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "block.h"
#include "subject.h"
#include "level.h"

class Board {
	protected:
    std::shared_ptr<Block> thisBlock;
    CellType nextType;
    int score;
    std::shared_ptr<Level> level;
    int countTurn;
    std::shared_ptr<TextDisplay> testDisplay;
    std::vector<std::vector<Cell>> allCells;
    public:
    virtual void left(int time);
    virtual void right(int time);
    virtual void rotate(bool isClockwise);
    virtual void down();
    virtual void drop();
    virtual void levelUp();
    virtual void levelDown();
    virtual void genThis();
    virtual void genNext();
    virtual std::vector<std::vector<char>> display();
    virtual void notify(Subject s);
};
