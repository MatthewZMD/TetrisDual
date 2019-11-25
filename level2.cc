#include <string>
#include <cstdlib>
#include "level.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "celltype.h"

Level2::Level2(std::string defaultFileName) : Level{2, defaultFileName} {}

CellType Level2::genBlock() const {
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
	}
	return types[rand() % 7];
}

Level Level2::levelDown() const {
	return Level1{defaultFileName};
}

Level Level2::levelUp() const {
	return Level3{defaultFileName};
}
