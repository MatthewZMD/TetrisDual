#ifndef BLINDDECORATOR_H
#define BLINDDECORATOR_H

#include "boarddecorator.h"

class BlindDecorator: public BoardDecorator{
	public:
		vector<vector<char>> display() override;
		~BlindDecorator();
		BlindDecorator(Board* board);
}

#endif
