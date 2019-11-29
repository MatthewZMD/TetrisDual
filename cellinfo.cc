#include "cellinfo.h"

CellInfo::CellInfo(Coordinate p, int bl, CellType t, std::vector<Cell*> sq): pos { p }, blockLevel { bl }, squad { sq } {}

CellInfo::~CellInfo() {}
