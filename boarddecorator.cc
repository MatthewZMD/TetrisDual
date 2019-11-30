#include "boarddecorator.h"

BoardDecorator::BoardDecorator(std::shared_ptr<Board>board): board { board } {}
int BoardDecorator::drop() {
	return board->drop();
}

int BoardDecorator::left(int time) {
	return board->left(time);
}

int BoardDecorator::right(int time) {
	return board->right(time);
}

void BoardDecorator::rotate(bool isClockwise, int time) {
	board->rotate(isClockwise, time);
}

bool BoardDecorator::down(int time) {
	return board->down(time);
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

void BoardDecorator::setNext(CellType newNext) {
	board->setNext(newNext);
}

bool BoardDecorator::isTurnOver() const {
	return board->isTurnOver();
}

Info& BoardDecorator::getInfo() {
	return board->getInfo();
}

void BoardDecorator::setTurnOver() {
	board->setTurnOver();
}

void BoardDecorator::noRandom(std::string fileName) {
	board->noRandom(fileName);
}

void BoardDecorator::random() {
	board->random();
}

void BoardDecorator::replaceBlock(CellType newType) {
	board->replaceBlock(newType);
}
