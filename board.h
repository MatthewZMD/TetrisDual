#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "block.h"
#include "subject.h"
#include "level.h"
#include "cell.h"
#include "level0.h"

class Board: public Subject, public Observer {
	public:
    virtual void left(int time) = 0;
    virtual void right(int time) = 0;
    virtual void rotate(bool isClockwise) = 0;
    virtual bool down() = 0;
    virtual void drop() = 0;
    virtual void levelUp() = 0;
    virtual void levelDown() = 0;
    virtual void genThis() = 0;
    virtual CellType genNext() = 0;
    virtual std::vector<std::vector<char>> display() = 0;
    virtual std::shared_ptr<Board> getBoard() = 0;
    virtual int getBoardNum() const = 0;
    virtual void setNext(CellType newNext) = 0;
    virtual bool isGameOver() const = 0;
    virtual Info& getInfo() = 0;

};

#endif
