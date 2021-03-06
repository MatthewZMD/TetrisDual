#include "level.h"

Level::Level(int level, std::string defaultFileName) : level{level}, defaultFileName{defaultFileName}, readFromFile{false}, nextLine{0} {}

int Level::heavyOffset() const {
    return 0;
}

bool Level::dropBrownBlock() const {
	return false;
}

void Level::setReadFromFile(std::string fileName) {
	readFromFile = true;

	std::ifstream fin;
	fin.open(fileName.c_str());

	sequence.clear();
	char c;
	CellType type = CellType::I;
	while (fin >> c) {
		switch (c) {
			case 'I':
				type = CellType::I;
				break;
			case 'J':
				type = CellType::J;
				break;
			case 'L':
				type = CellType::L;
				break;
			case 'O':
				type = CellType::O;
				break;
			case 'S':
				type = CellType::S;
				break;
			case 'Z':
				type = CellType::Z;
				break;
			case 'T':
				type = CellType::T;
				break;
		}
		sequence.emplace_back(type);
	}
	nextLine = 0;

	fin.close();
}

void Level::unsetReadFromFile() {
	readFromFile = false;
	sequence.clear();
	nextLine = 0;
}

int Level::getLevel() const {
	return level;
}

CellType Level::genBlockFromFile() {
	CellType type = sequence.at(nextLine);
	nextLine = (nextLine + 1) % sequence.size();
	return type;
}
