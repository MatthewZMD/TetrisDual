#ifndef LEVEL2_H
#define LEVEL2_H

#include <string>
#include "level.h"
#include "celltype"

class Level2 : public Level {
	public:
		Level2(std::string defaultFileName);
		CellType genBlock() const override;
		Level levelDown() const override;
		std::shared_ptr<Level> levelUp() const override;
};

#endif
