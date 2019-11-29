#ifndef HEAVYDECORATOR_H
#define HEAVYDECORATOR_H
#include <memory>
#include "boarddecorator.h"

class HeavyDecorator: public BoardDecorator {
	public:
    int left(int time) override;
    int right(int time) override;
    HeavyDecorator(std::shared_ptr<Board> board);
};

#endif
