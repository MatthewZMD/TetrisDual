#include "heavydecorator.h"

using namespace std;

void HeavyDecorator::left(int time) {
	board->left(int time);
	board->down();
}

void HeavyDecorator::right(int time) {
	board->right(int time);
	board->down();
}

HeavyDecorator::~HeavyDecorator() {
	delete board;
}

HeavyDecorator::HeavyDecorator(Board* board): board{board} {}

