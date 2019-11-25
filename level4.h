#ifndef LEVEL4_H
#define LEVEL4_H

#include <string>
#include "level.h"
#include "celltype.h"

class Level4 : public Level {
	public:
		Level4(std::string defaultFileName);
		CellType genBlock() const override;
		Level levelDown() const override;
		Level levelUp() const override;
		int heavyOffset() const override;
		bool dropBrownBlock() const override;
};

#endif
