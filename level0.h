#ifndef LEVEL0_H
#define LEVEL0_H
#include <memory>
#include <string>
#include "level.h"
#include "level1.h"
class Level0 : public Level {
	public:
		Level0(std::string defaultFileName);
		CellType genBlock() override;
		std::shared_ptr<Level> levelDown() const override;
		std::shared_ptr<Level> levelUp() const override;
};

#endif
