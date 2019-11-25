#include "boarddecorator.h"

using namespace std;

void BoardDecorator::left(int time) {
	board->left(int time);
}

void BoardDecorator::right(int time) {
	board->right(int time);
}

void BoardDecorator::rotate(bool isClockwise) {
	board->rotate(bool isClockwise);
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

vector<vector<char>> BoardDecorator::display() {
	board->display();
}

void BoardDecorator::notify(Subject s) {
	board->notify(s);
}

vector<vector<char>> BoardDecorator::gettest() {
	board->gettest();
}
