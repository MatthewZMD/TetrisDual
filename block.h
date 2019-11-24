#ifndef _BLOCk_H_
#define _BLOCk_H_
#include <vector>
#include <memory>
#include "cell.h"

class Block {
    public:
    Block(CellType type);
    std::shared_ptr<std::shared_ptr<Cell>> cells;
};

#endif
