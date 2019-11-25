#ifndef _BLOCk_H_
#define _BLOCk_H_
#include <vector>
#include <memory>
#include "cell.h"

class Block {
    /* Recalibrate the bottom left Coordinate, run after a block movement */
    void recaliBtmLft();
    public:
    std::vector<std::shared_ptr<Cell>> cells;
    Coordinate btmLft;
    Block(CellType t, int l, std::vector<std::shared_ptr<Cell>> cells);
};

#endif
