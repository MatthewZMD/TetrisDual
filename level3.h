#ifndef LEVEL3_H
#define LEVEL3_H

#include <memory>
#include <cstdlib>
#include <string>
#include "level.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "celltype.h"

class Level3 : public Level {
	public:
    Level3(std::string defaultFileName);
    CellType genBlock() const override;
    std::shared_ptr<Level> levelDown() const override;
    std::shared_ptr<Level> levelUp const override;
    int heavyOffset() const override;
};

#endif
