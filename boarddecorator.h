#ifndef BOARDDECORATOR_H
#define BOARDDECORATOR_H
#include <memory>
#include "board.h"

class BoardDecorator: public Board {
	protected:
    std::shared_ptr<Board> board;
	public:
    BoardDecorator(std::shared_ptr<Board>board);
    virtual ~BoardDecorator() = default;
    virtual void left(int time) override;
    virtual void right(int time) override;
    virtual void rotate(bool isClockwise) override;
    virtual void down() override;
    virtual void drop() override;
    virtual void levelUp() override;
    virtual void levelDown() override;
    virtual std::vector<std::vector<char>> display() override;
    virtual void notify(Subject s) override;
    virtual Block genBlock() override;
};
#endif
