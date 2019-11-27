#ifndef LEVEL2_H
#define LEVEL2_H

#include <memory>
#include <cstdlib>
#include <string>
#include "level.h"
#include "level1.h"
#include "level3.h"

class Level2 : public Level {
	public:
		Level2(std::string defaultFileName);
		CellType genBlock() const override;
		std::shared_ptr<Level> levelDown() const override;
		std::shared_ptr<Level> levelUp() const override;
};

#endif
