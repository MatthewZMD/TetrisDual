#include "heavydecorator.h"

void HeavyDecorator::left(int time) {
	board->left(time);
	if (board->down() && board->down()) {
		board->drop();
	}
}

void HeavyDecorator::right(int time) {
	board->right(time);
	if (board->down() && board->down()) {
		board->drop();
	}
}

HeavyDecorator::HeavyDecorator(std::shared_ptr<Board> board): BoardDecorator { board }{
	this->observers = board->observers;

}
