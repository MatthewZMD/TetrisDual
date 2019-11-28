#include "cellstate.h"

CellState::CellState(): cellStatus { CellStatus::Alive } {}

CellState::CellState(CellStatus status): cellStatus { status } {}

CellState::~CellState() {  };
