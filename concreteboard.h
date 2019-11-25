#ifndef CONCRETEBOARD_H
#define CONCRETEBOARD_H
#include "board.h"
#include "level.h"

class ConcreteBoard: public Board {
	private:
    std::shared_ptr<Block> thisBlock;
    std::shared_ptr<Block> nextBlock;
    int score;
    std::shared_ptr<Level> level;
    int countTurn;
    TextDisplay testDisplay;
    std::vector<std::vector<Cell>> allCells;
	public:
    void left(int time) override;
    void right(int time) override;
    void rotate(bool isClockwise) override;
    void down() override;
    void drop() override;
    void levelUp() override;
    void levelDown() override;
    std::vector<std::vector<char>> display() override;
    void notify(Subject s) override;
    Block genBlock() override;
};
#endif
