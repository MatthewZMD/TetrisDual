#ifndef LEVEL0_H
#define LEVEL0_H

#include <string>
#include "level.h"
#include "celltype.h"

class Level0 : public Level {
	public:
		Level0(std::string defaultFileName);
		CellType genBlock() const override;
		Level levelDown() const override;
		Level levelUp() const override;
};

#endif
