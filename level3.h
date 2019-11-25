#ifndef LEVEL3_H
#define LEVEL3_H
#include <cstdlib>
#include <string>
#include "level.h"

class Level3 : public Level {
	public:
    Level3(std::string defaultFileName);
    CellType genBlock() const override;
    Level levelDown() const override;
    std::shared_ptr<Level> levelUp const override;
    int heavyOffset() const override;
};

#endif
