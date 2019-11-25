#include "forcedecorator.h"

ForceDecorator::ForceDecorator(std::shared_ptr<Board> board, CellType giventype): BoardDecorator { board }, giventype{giventype} {}

Block genBlock() {}
