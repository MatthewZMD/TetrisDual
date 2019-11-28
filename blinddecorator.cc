#include "blinddecorator.h"

std::vector<std::vector<char>> BlindDecorator::display() {
	std::vector<std::vector<char>> a = board->display();
	for (int i = 2; i < 12; ++i) {
		for (int j = 2; j < 9; ++j) {
			a[i][j] = '?';
		}
	}
	return a;
}

BlindDecorator::BlindDecorator(std::shared_ptr<Board> board): BoardDecorator {board} {
	this->observers = board->observers;
}

