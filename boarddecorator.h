#ifndef BOARDDECORATOR_H
#define BOARDDECORATOR_H
#include <memory>
#include "board.h"

class BoardDecorator: public Board {
	public:
    std::shared_ptr<Board> board;
    BoardDecorator(std::shared_ptr<Board>board);
    virtual ~BoardDecorator() = default;
    virtual int left(int time) override;
    virtual int right(int time) override;
    virtual void rotate(bool isClockwise, int time) override;
    virtual bool down(int time) override;
    virtual int drop(int time) override;
    virtual void levelUp() override;
    virtual void levelDown() override;
    virtual std::vector<std::vector<char>> display() override;
    virtual void genThis() override;
    virtual CellType genNext() override;
    std::shared_ptr<Board> getBoard() override;
    virtual int getBoardNum() const override;
    virtual void setNext(CellType newNext) override;
    bool isTurnOver() const override;
    Info& getInfo() override;
    void setTurnOver() override;
    void noRandom(std::string filename) override;
    void random() override;
    void replaceBlock(CellType newType) override;
};
#endif
