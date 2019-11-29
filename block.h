#ifndef _BLOCk_H_
#define _BLOCk_H_
#include <vector>
#include <memory>
#include "cell.h"

class Block {
    public:
    /* Recalibrate the bottom left Coordinate, run after a block movement */
    void recaliBtmLft();
    std::vector<Cell*> cells;
    Coordinate btmLft;
    Block(CellType t, int l, std::vector<Cell*> cells);
};

#endif
