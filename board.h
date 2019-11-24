#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "block.h"
#include "subject.h"

class Board {
    Block thisBlock;
    Block nextBlock;
    int score;
    Level level;
    int countTurn;
    TextDisplay textDisplay;

    virtual void left();
    virtual void right();
    virtual void rotate(bool isClockwise);
    virtual void down();
    virtual void drop();
    virtual void levelUp();
    virtual void levelDown();
    virtual std::vector<std::vector<char>> display();
    virtual void notify(Subject s);

    virtual ~Board() = 0;
};
