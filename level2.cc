#include "level2.h"

Level2::Level2(std::string defaultFileName) : Level{2, defaultFileName} {}

CellType Level2::genBlock() {
	if (readFromFile) {
		return genBlockFromFile();
	}
	const CellType types[7] = {
		CellType::I,
		CellType::J,
		CellType::L,
		CellType::O,
		CellType::S,
		CellType::Z,
		CellType::T
	};
	return types[rand() % 7];
}

std::shared_ptr<Level> Level2::levelDown() const {
	return std::shared_ptr<Level>(new Level1{defaultFileName});
}

std::shared_ptr<Level> Level2::levelUp() const {
	return std::shared_ptr<Level>(new Level3{defaultFileName});
}
