#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include "level.h"
#include "celltype.h"

class Level3 : public Level {
	public:
		Level3(std::string defaultFileName);
		CellType genBlock() const override;
		Level levelDown() const override;
		Level levelUp const override;
		int heavyOffset() const override;
};

#endif
