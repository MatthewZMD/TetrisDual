#ifndef _CONCRETEBOARD_H_
#define _CONCRETEBOARD_H_
#include "board.h"
#include "cellstate.h"
#include "boardinfo.h"

class ConcreteBoard: public Board{
    CellState dummyState;
    public:
    int boardNum;
    std::shared_ptr<Block> thisBlock;
    CellType nextType;
    int score;
    std::shared_ptr<Level> level;
    int countTurn;
    std::vector<std::vector<Cell>> allCells;
    bool turnGG = false;
    ConcreteBoard(int boardNum, std::string fileName, int l);
    BoardInfo boardInfo;
    void genThis() override;
    CellType genNext() override;
    int left(int time) override;
    int right(int time) override;
    void rotate(bool isClockwise, int time) override;
    bool down(int time) override;
    int drop() override;
    void levelUp() override;
    void levelDown() override;
    std::vector<std::vector<char>> display() override;
    std::shared_ptr<Board> getBoard() override;
    int getBoardNum() const override;
    void setNext(CellType newNext) override;
    bool isTurnOver() const override;
    Info& getInfo() override;
    void setTurnOver() override;
    void noRandom(std::string fileName) override;
    void random() override;
    void replaceBlock(CellType NewType) override;
};
#endif
