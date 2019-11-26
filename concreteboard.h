#ifndef _CONCRETEBOARD_H_
#define _CONCRETEBOARD_H_
#include "board.h"

class ConcreteBoard: public Board, public Subject {
    protected:
    std::shared_ptr<Block> thisBlock;
    CellType nextType;
    int score;
    std::shared_ptr<Level> level;
    int countTurn;
    std::shared_ptr<TextDisplay> testDisplay;
    std::vector<std::vector<Cell>> allCells;
	public:
    void genThis() override;
    void genNext() override;
    void left(int time) override;
    void right(int time) override;
    void rotate(bool isClockwise) override;
    bool down() override;
    void drop() override;
    void levelUp() override;
    void levelDown() override;
    std::vector<std::vector<char>> display() override;
    void notify(Subject s) override;
};
#endif
