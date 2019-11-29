#include "level1.h"

Level1::Level1(std::string defaultFileName) : Level{1, defaultFileName} {}

CellType Level1::genBlock() {
	if (readFromFile) {
		return genBlockFromFile();
	}
	const CellType types[12] = {
		CellType::S,
		CellType::Z,
		CellType::I,
		CellType::I,
		CellType::J,
		CellType::J,
		CellType::L,
		CellType::L,
		CellType::O,
		CellType::O,
		CellType::T,
		CellType::T
	};
	return types[rand() % 12];
}

std::shared_ptr<Level> Level1::levelDown() const {
	return std::make_shared<Level0>(defaultFileName);
}

std::shared_ptr<Level> Level1::levelUp() const {
	return std::make_shared<Level2>(defaultFileName);
}
