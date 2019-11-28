#include "level0.h"

Level0::Level0(std::string defaultFileName) : Level{0, defaultFileName} {
	setReadFromFile(defaultFileName);
}

CellType Level0::genBlock() {
	// level 0 must have readFromFile true
	return genBlockFromFile();
}

std::shared_ptr<Level> Level0::levelDown() const {
	return std::shared_ptr<Level>(new Level0{defaultFileName});
}

std::shared_ptr<Level> Level0::levelUp() const {
	return std::shared_ptr<Level>(new Level1{defaultFileName});
}
