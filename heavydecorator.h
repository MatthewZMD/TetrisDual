#ifndef HEAVYDECORATOR_H
#define HEAVYDECORATOR_H
#include <memory>
#include "boarddecorator.h"

class HeavyDecorator: public BoardDecorator {
	public:
    void left(int time) override;
    void right(int time) override;
    HeavyDecorator(std::shared_ptr<Board> board);
    void notify(Subject& s) override;
};

#endif
