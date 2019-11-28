#ifndef _CONCRETEBOARD_H_
#define _CONCRETEBOARD_H_
#include "board.h"

class ConcreteBoard: std::enable_shared_from_this<ConcreteBoard>, public Board{
    public:
    int boardNum;
    std::shared_ptr<Block> thisBlock;
    CellType nextType;
    int score;
    std::shared_ptr<Level> level;
    int countTurn;
    std::vector<std::vector<Cell>> allCells;
    bool isGG = false;
    ConcreteBoard(int boardNum, std::string fileName);
    void genThis() override;
    CellType genNext() override;
    void left(int time) override;
    void right(int time) override;
    void rotate(bool isClockwise) override;
    bool down() override;
    void drop() override;
    void levelUp() override;
    void levelDown() override;
    std::vector<std::vector<char>> display() override;
    void notify(Subject& s) override;
    std::shared_ptr<Board> getBoard() override;
    int getBoardNum() const override;
    void setNext(CellType newNext) override;
    bool isGameOver() const override;
    Info& getInfo() override; // TODO
    State& getState() override; // TODO
};
#endif
