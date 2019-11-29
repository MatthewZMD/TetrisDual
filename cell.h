#ifndef _CELL_H_
#define _CELL_H_
#include <memory>
#include <vector>
#include "subject.h"
#include "observer.h"
#include "celltype.h"
#include "cellinfo.h"
#include "cellstate.h"

class Cell: public Observer, public Subject {
    CellInfo cellInfo;
    public:
    Coordinate pos;
    int blockLevel;
    CellType type;
    std::vector<Cell*> squad;
    CellState cellState;
    Cell(Coordinate pos);
    void restore();
    void set(CellType t, int bl, std::vector<Cell*> squad);
    void notify(Subject& s) override;
    bool isEmpty() const;
    Info& getInfo() override;
    State& getState() override;
    CellInfo cellInfo;
    CellState cellState;
};

#endif
