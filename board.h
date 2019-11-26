#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "block.h"
#include "subject.h"
#include "level.h"

class Board {
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
};
