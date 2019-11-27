#ifndef CELLSTATE_H
#define CELLSTATE_H

#include "state.h"

enum CellStatus {
	case Restore;
	case Down;
};

struct {
	CellStatus cellStatus;
};

#endif
