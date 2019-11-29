#include "heavydecorator.h"

int HeavyDecorator::left(int time) {
	board->left(time);
	int lineRemove = 0;
	if (board->down() && board->down()) {
		lineRemove = board->drop();
	}
	notifyObservers();
	return lineRemove;
}

int HeavyDecorator::right(int time) {
	board->right(time);
	int lineRemove = 0;
	if (board->down() && board->down()) {
		lineRemove = board->drop();
	}
	notifyObservers();
	return lineRemove;
}

HeavyDecorator::HeavyDecorator(std::shared_ptr<Board> board): BoardDecorator { board }{
	this->observers = board->observers;

}
