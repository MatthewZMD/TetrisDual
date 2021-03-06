#include "heavydecorator.h"

int HeavyDecorator::left(int time) {
	board->left(time);
	int lineRemove = 0;
	if (!board->down(1) || !board->down(1)) {
		lineRemove = board->drop();
	}
	notifyObservers();
	return lineRemove;
}

int HeavyDecorator::right(int time) {
	board->right(time);
	int lineRemove = 0;
	if (!board->down(1) || !board->down(1)) {
		lineRemove = board->drop();
	}
	notifyObservers();
	return lineRemove;
}

HeavyDecorator::HeavyDecorator(std::shared_ptr<Board> board): BoardDecorator { board }{
	for (auto &i : board->observers) {
              attach(i);
        }
}
