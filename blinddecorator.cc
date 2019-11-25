#include "blinddecorator.h"

using namespace std;

vector<vector<char>> BlindDecorator::display() {
	vector<vector<char>> a = board->display();
	for (int i = 2; i < 12; ++i) {
		for (int j = 2; j < 9; ++j) {
			a[i][j] = '?';
		}
	}
	return a;
}

BlindDecorator::~BlindDecorator() {
	delete board;
}

BlindDecorator::BlindDecorator(Board* board): thisBlock(board->thisBlock), nextBlock(board->nextBlock), score(board->score), level(board->level), countTurn(board->countTurn), textDisplay(board->textDisplay) {}


