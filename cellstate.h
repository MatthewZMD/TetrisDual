#ifndef CELLSTATE_H
#define CELLSTATE_H
#include "state.h"

enum CellStatus {
	Dead, Down, Alive
};

class CellState: public State {
    public:
	CellStatus cellStatus;
    CellState();
    CellState(CellStatus status);
};

#endif
