#ifndef _BLOCk_H_
#define _BLOCk_H_
#include <vector>
#include <memory>
#include "cell.h"

class Block {
    /* Recalibrate the bottom left Coordinate, run after a block movement */
    void recaliBtmLft();
    public:
    Coordinate btmLft;
    std::vector<std::shared_ptr<Cell>> cells;
    Block(CellType t, std::vector<std::vector<std::shared_ptr<Cell>>> allCells);
};

#endif
