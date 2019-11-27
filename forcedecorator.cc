#include "forcedecorator.h"

ForceDecorator::ForceDecorator(std::shared_ptr<Board> board, CellType giventype): BoardDecorator { board }, giventype{giventype} {}

CellType ForceDecorator::genNext() {
    return giventype;
} 
