#include "level3.h"

Level3::Level3() : Level{3, defaultFileName} {}

CellType Level3::genBlock() {
	if (readFromFile) {
		return genBlockFromFile();
	}
	const CellType types[9] = {
		CellType::I,
		CellType::J,
		CellType::L,
		CellType::O,
		CellType::T,
		CellType::S,
		CellType::Z
	};
	return types[rand() % 9];
}

std::shared_ptr<Level> Level3::levelDown() const {
	return std::shared_ptr<Level>(new Level2{defaultFileName});
}

std::shared_ptr<Level> Level3::levelUp() const {
	return std::shared_ptr<Level>(new Level4{defaultFileName});
}

int Level3::heavyOffset() const {
	return 1;
}
