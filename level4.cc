#include "level4.h"

Level4::Level4() : Level{4, defaultFileName} {}

CellType Level4::genBlock() const {
	if (readFromFile) {
		return genBlockFromFile();
	}
	return levelDown().genBlock();
}

std::shared_ptr<Level> Level4::levelDown() const {
	return std::shared_ptr<Level>(new Level3{defaultFileName});
}

std::shared_ptr<Level> Level4::levelUp() const {
	return std::shared_ptr<Level>(new Level4{defaultFileName});
}

int Level4::heavyOffset() const {
	return 1;
}

bool Level4::dropBrownBlock() const {
	return true;
}
