#include "forcedecorator.h"

ForceDecorator::ForceDecorator(std::shared_ptr<Board> board, CellType giventype): BoardDecorator { board }, giventype{giventype} {
	for (auto &i : board->observers) {
              attach(i);
        }
	board->replaceBlock(giventype);
}
 
