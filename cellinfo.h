#ifndef CELLINFO_H
#define CELLINFO_H

#include <vector>
#include "info.h"
#include "coordinate.h"
#include "celltype.h"
#include "cell.h"

struct CellInfo : Info {
	Coordinate pos;
	int blockLevel;
	CellType type;
	std::vector<Cell*> squad;
};

#endif
