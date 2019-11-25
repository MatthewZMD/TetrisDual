#ifndef CONCRETEBOARD_H
#define CONCRETEBOARD_H

#include "board.h"

class ConcreteBoard: public Board {
	private:
		Block thisBlock;
		Block nextBlock;
		int score;
		Level level;
		int countTurn;
		TextDisplay testDisplay;
		std::vector<std::vector<Cell>> allCells;
	public:
		void left(int time) override;
		void right(int time) override;
		void rotate(bool isClockwise) override;
		void down() override;
		void drop() override;
		void levelUp() override;
		void levelDown() override;
		std::vector<std::vector<char>> display() override;
		void notify(Subject s) override;
		std::vector<std::vector<char>> gettest() override;
		Block genBlock() override;
		
};
#endif