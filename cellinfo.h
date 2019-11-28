#ifndef CELLINFO_H
#define CELLINFO_H
#include <vector>
#include "info.h"
#include "coordinate.h"
#include "celltype.h"

class Cell;

struct CellInfo : public Info {
	Coordinate pos;
	int blockLevel;
	CellType type;
	std::vector<Cell*> squad;
    CellInfo(Coordinate p, int bl, CellType t, std::vector<Cell*> sq);
    ~CellInfo() override;
};

#endif
