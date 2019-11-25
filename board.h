#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "block.h"
#include "subject.h"

class Board {
    public:
        virtual void left(int time) = 0;
        virtual void right(int time) = 0;
        virtual void rotate(bool isClockwise) = 0;
        virtual void down() = 0;
        virtual void drop() = 0;
        virtual void levelUp() = 0;
        virtual void levelDown() = 0;
        virtual Block genBlock() = 0;
        virtual std::vector<std::vector<char>> display() = 0;
        virtual void notify(Subject s) = 0;
        virtual std::vector<std::vector<char>> gettest() = 0;
        virtual ~Board() = 0;
        bool isDecorator = 0;
};
