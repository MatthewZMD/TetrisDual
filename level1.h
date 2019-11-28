#ifndef LEVEL1_H
#define LEVEL1_H

#include <memory>
#include <string>
#include <cstdlib>
#include "level.h"
#include "level0.h"
#include "level2.h"

class Level1 : public Level {
	public:
		Level1(std::string defaultFileName);
		CellType genBlock() override;
		std::shared_ptr<Level> levelDown() const override;
		std::shared_ptr<Level> levelUp() const override;
};

#endif
