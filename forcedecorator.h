#ifndef FORCEDECORATOR_H
#define FORCEDECORATOR_H

#include "boarddecorator.h"

class ForceDecorator: public BoardDecorator {
	public:
	       ~ForceDecorator();
	       ForceDecorator(Board* board, Block block);
};

#endif
