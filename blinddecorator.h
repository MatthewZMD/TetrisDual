#ifndef BLINDDECORATOR_H
#define BLINDDECORATOR_H
#include "boarddecorator.h"

class BlindDecorator: public BoardDecorator{
	public:
    std::vector<std::vector<char>> display() override;
    BlindDecorator(Board* board);
};

#endif
