#ifndef FORCEDECORATOR_H
#define FORCEDECORATOR_H
#include "boarddecorator.h"

class ForceDecorator: public BoardDecorator {
	CellType giventype;
	public:
    ForceDecorator(std::shared_ptr<Board> board, CellType giventype);
    Block genBlock() override;
};

#endif
