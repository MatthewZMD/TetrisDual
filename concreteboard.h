#ifndef _CONCRETEBOARD_H_
#define _CONCRETEBOARD_H_
#include "board.h"

class ConcreteBoard: public Board, public Subject {
	public:
    Block genBlock() override;
    void left(int time) override;
    void right(int time) override;
    void rotate(bool isClockwise) override;
    void down() override;
    void drop() override;
    void levelUp() override;
    void levelDown() override;
    std::vector<std::vector<char>> display() override;
    void notify(Subject s) override;
};
#endif
