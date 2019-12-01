#include "boarddecorator.h"
#include "boardinfo.h"


BoardDecorator::BoardDecorator(std::shared_ptr<Board>board): board { board } {
    countD = board->countD;
}

int BoardDecorator::drop() {
	int result = board->drop();
	notifyObservers();
	return result;

}

int BoardDecorator::left(int time) {
	int result = board->left(time);
	notifyObservers();
	return result;
}

int BoardDecorator::right(int time) {
	int result = board->right(time);
	notifyObservers();
	return result;
}

void BoardDecorator::rotate(bool isClockwise, int time) {
	board->rotate(isClockwise, time);
	notifyObservers();
}

bool BoardDecorator::down(int time) {
	bool result = board->down(time);
	notifyObservers();
	return result;
}

void BoardDecorator::levelUp() {
	board->levelUp();
	notifyObservers();
}

void BoardDecorator::levelDown() {
	board->levelDown();
	notifyObservers();
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
	notifyObservers();
}

bool BoardDecorator::isTurnOver() const {
	return board->isTurnOver();
}

Info& BoardDecorator::getInfo() {
        BoardInfo& info = dynamic_cast<BoardInfo&>(board->getInfo());
	info.boardData = display();
	return info;
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
	notifyObservers();
}
