#ifndef BLINDDECORATOR_H
#define BLINDDECORATOR_H
#include <vector>
#include "boarddecorator.h"

class BlindDecorator: public BoardDecorator{
	public:
    std::vector<std::vector<char>> display() override;
    BlindDecorator(std::shared_ptr<Board> board);
};

#endif
