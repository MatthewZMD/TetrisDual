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
CellType BoardDecorator::genNext() {
	return board->genNext();
}

std::shared_ptr<Board> BoardDecorator::getBoard() {
    return board->getBoard();
}

int BoardDecorator::getBoardNum() const {
    return board->getBoardNum();
}

void BoardDecorator::notify(Subject& s) {
	board->notify(s);
}

void BoardDecorator::setNext(CellType newNext) {
	board->setNext(newNext);
}

bool BoardDecorator::isGameOver() const {
	return board->isGameOver();
}

Info& BoardDecorator::getInfo() {
	return board->getInfo();
}

