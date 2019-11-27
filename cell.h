#ifndef _CELL_H_
#define _CELL_H_
#include <memory>
#include <vector>
#include "subject.h"
#include "observer.h"
#include "coordinate.h"
#include "cell.h"
#include "celltype.h"
#include "cellinfo.h"
#include "cellstate.h"

class Cell: public Observer, public Subject {
    public:
    Coordinate pos;
    int blockLevel;
    CellType type;
    std::vector<Cell*> squad;

    Cell(Coordinate pos);
    void restore();
    void set(CellType t, int bl, std::vector<Coordinate> squad);
    void notify(Subject& s);
    bool isEmpty() const;

    CellInfo getInfo() const;
    CellState getState() const;
    void setState(CellState s);

    private:
    CellState cellState;
};

#endif
