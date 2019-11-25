#include <string>
#include <cstdlib>
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "celltype.h"

Level1::Level1(std::string defaultFileName) : Level{1, defaultFileName} {}

CellType Level1::genBlock() const {
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
	}
	return types[rand() % 12];
}

Level Level1::levelDown() const {
	return Level0{defaultFileName};
}

Level Level1::levelUp() const {
	return Level2{defaultFileName};
}
