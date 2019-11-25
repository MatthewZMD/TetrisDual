#include <string>
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "celltype.h"

Level0::Level0(std::string defaultFileName) : Level{0, defaultFileName} {
	setReadFromFile(defaultFileName);
}

CellType Level0::genBlock() const {
	// level 0 must have raedFromFile true
	return genBlockFromFile();
}

Level Level0::levelDown() const {
	return Level0{defaultFileName};
}

Level Level0::levelUp() const {
	return Level1{defaultFileName};
}
