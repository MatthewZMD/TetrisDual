#include "heavydecorator.h"

void HeavyDecorator::left(int time) {
	board->left(time);
	board->down();
}

void HeavyDecorator::right(int time) {
	board->right(time);
	board->down();
}

HeavyDecorator::HeavyDecorator(std::shared_ptr<Board> board): BoardDecorator { board } {}
