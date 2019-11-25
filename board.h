#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "block.h"
#include "subject.h"

class Board {
    virtual void left(int time);
    virtual void right(int time);
    virtual void rotate(bool isClockwise);
    virtual void down();
    virtual void drop();
    virtual void levelUp();
    virtual void levelDown();
    virtual std::vector<std::vector<char>> display();
    virtual void notify(Subject s);
    virtual std::vector<std::vector<char>> gettest();
    virtual ~Board() = 0;
};
