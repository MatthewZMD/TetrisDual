#ifndef CONCRETEBOARD_H
#define CONCRETEBOARD_H

class ConcreteBoard: public Board {
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
		std::vector<std::vector
		Block thisBlock;
		Block nextBlock;
		int score;
		Level level;
		int countTurn;
		TextDisplay testDisplay;
};
