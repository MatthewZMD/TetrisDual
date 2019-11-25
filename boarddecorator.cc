#include "boarddecorator.h"

BoardDecorator::BoardDecorator(std::shared_ptr<Board>board): board { board } {}

void BoardDecorator::left(int time) {
	board->left(time);
}

void BoardDecorator::right(int time) {
	board->right(time);
}

void BoardDecorator::rotate(bool isClockwise) {
	board->rotate(isClockwise);
}

void BoardDecorator::down() {
	board->down();
}

void BoardDecorator::levelUp() {
	board->levelUp();
}

void BoardDecorator::levelDown() {
	board->levelDown();
}

std::vector<std::vector<char>> BoardDecorator::display() {
	board->display();
}

void BoardDecorator::notify(Subject s) {
	board->notify(s);
}
