#include <string>
#include <cstdlib>
#include "level.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "celltype.h"

Level3::Level3() : Level{3, defaultFileName} {}

CellType Level3::genBlock() const {
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

Level Level3::levelDown() const {
	return Level2{defaultFileName};
}

Level Level3::levelUp() const {
	return Level4{defaultFileName};
}

int Level3::heavyOffset() const {
	return 1;
}
