#ifndef BOARDDECORATOR_H
#define BOARDDECORATOR_H
#include <memory>
#include "board.h"

class BoardDecorator: public Board {
	public:
    std::shared_ptr<Board> board;
    BoardDecorator(std::shared_ptr<Board>board);
    virtual ~BoardDecorator() = default;
    virtual void left(int time) override;
    virtual void right(int time) override;
    virtual void rotate(bool isClockwise) override;
    virtual bool down() override;
    virtual void drop() override;
    virtual void levelUp() override;
    virtual void levelDown() override;
    virtual std::vector<std::vector<char>> display() override;
    virtual void genThis() override;
    virtual CellType genNext() override;
    std::shared_ptr<Board> getBoard() override;
    virtual int getBoardNum() const override;
    virtual void setNext(CellType newNext) override;
    bool isGameOver() const override;
    Info& getInfo() override;
};
#endif
