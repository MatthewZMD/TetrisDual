#include "blinddecorator.h"

std::vector<std::vector<char>> BlindDecorator::display() {
	std::vector<std::vector<char>> a = board->display();
	for (int i = 6; i < 16; ++i) {
		for (int j = 0; j < 11; ++j) {
			a[i][j] = '?';
		}		
	}
	for (int i = 0; i < 18; ++i) {
		for (int j = 2; j < 9; ++j) {
			a[i][j] = '?';
		}
	}
	return a;
}

BlindDecorator::BlindDecorator(std::shared_ptr<Board> board): BoardDecorator {board} {
	for (auto &i : board->observers) {
	      attach(i);
	}
}
