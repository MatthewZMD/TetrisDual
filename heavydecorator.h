#ifndef HEAVYDECORATOR_H
#define HEAVYDECORATOR_H

#include "boarddecorator.h"

class HeavyDecorator: public BoardDecorator {
	public:
		void left(int time) override;
		void right(int time) override;
		~HeavyDecorator();
		HeavyDecorator(Board* board);
};

#endif
