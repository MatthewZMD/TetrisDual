#ifndef LEVEL4_H
#define LEVEL4_H

#include <memory>
#include <cstdlib>
#include <string>
#include "level.h"
#include "level3.h"
#include "level4.h"
#include "celltype.h"

class Level4 : public Level {
	public:
		Level4(std::string defaultFileName);
		CellType genBlock() const override;
		std::shared_ptr<Level> levelDown() const override;
		std::shared_ptr<Level> levelUp() const override;
		int heavyOffset() const override;
		bool dropBrownBlock() const override;
};

#endif
