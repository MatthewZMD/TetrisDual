#ifndef LEVEL4_H
#define LEVEL4_H

#include <memory>
#include <cstdlib>
#include <string>
#include "level.h"
#include "level3.h"

class Level4 : public Level {
	public:
		Level4(std::string defaultFileName);
		CellType genBlock() override;
		std::shared_ptr<Level> levelDown() const override;
		std::shared_ptr<Level> levelUp() const override;
		int heavyOffset() const override;
		bool dropBrownBlock() const override;
};

#endif
