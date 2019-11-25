#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
#include "celltype.h"

class Level1 : public Level {
	public:
		Level1(std::string defaultFileName);
		CellType genBlock() const override;
		Level levelDown() const override;
		std::shared_ptr<Level> levelUp() const override;
};

#endif
