#ifndef BOARDDECORATOR_H
#define BOARDDECORATOR_H

#include "board.h"

class BoardDecorator: public Board {
	protected:
		Board* board;
	public:
		virtual ~operation() = default;
		virtual void left(int time) override;
		virtual void right(int time) override;
		virtual void rotate(bool isClockwise) override;
		virtual void down() override;
		virtual void drop() override;
		virtual void levelUp() override;
		virtual void levelDown() override;
		virtual vector<vector<char>> display() override;
		virtual void notify(Subject s) override;
		virtual vector<vector<char>> gettest() override;
};
#endif
