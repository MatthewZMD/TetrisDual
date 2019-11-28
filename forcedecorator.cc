#include "forcedecorator.h"

ForceDecorator::ForceDecorator(std::shared_ptr<Board> board, CellType giventype): BoardDecorator { board }, giventype{giventype} {
	this->observers = board->observers;
}

CellType ForceDecorator::genNext() {
    return giventype;
} 
