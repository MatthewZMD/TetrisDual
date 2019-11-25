#include <string>
#include <cstdlib>
#include "level.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "celltype.h"

Level4::Level4() : Level{4, defaultFileName} {}

CellType Level4::genBlock() const {
	if (readFromFile) {
		return genBlockFromFile();
	}
	return levelDown().genBlock();
}

Level Level4::levelDown() const {
	return Level3{defaultFileName};
}

Level Level4::levelUp() const {
	return Level4{defaultFileName};
}

int Level4::heavyOffset() const {
	return 1;
}

bool Level4::dropBrownBlock() const {
	return true;
}
