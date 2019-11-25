#include "boarddecorator.h"

using namespace std;

void BoardDecorator::left(int time) {
	board->left(int time);
}

void BoardDecorator::right(int time) {
	board->right(int time);
}

void rotate(bool isClockwise) {
	board->rotate(bool isClockwise);
}

void down() {
	board->down();
}

void levelUp() {
	board->levelUp();
}

void levelDown() {
	board->levelDown();
}

vector<vector<char>> display() {
	board->display();
}

void notify(Subject s) {
	board->notify(s);
}

vector<vector<char>> gettest() {
	board->gettest();
}
