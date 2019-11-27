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

bool BoardDecorator::down() {
	return board->down();
}

void BoardDecorator::levelUp() {
	board->levelUp();
}

void BoardDecorator::levelDown() {
	board->levelDown();
}

std::vector<std::vector<char>> BoardDecorator::display() {
	return board->display();
}


void BoardDecorator::genThis() {
	board->genThis();
}

void BoardDecorator::genNext() {
	board->genNext();
}

std::shared_ptr<Board> BoardDecorator::getBoard() {
    return board->getBoard();
}

int BoardDecorator::getBoardNum() const {
    return board->getBoardNum();
}
