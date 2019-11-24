#ifndef _CELL_H_
#define _CELL_H_
#include <vector>
#include "cell.h"

class Block {
    public:
    Block();
    Cell** cells;
    void init();
};

#endif
