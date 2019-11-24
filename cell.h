#ifndef _CELL_H_
#define _CELL_H_
#include <vector>
#include "subject.h"
#include "observer.h"
#include "coordinate.h"

class Cell: public Observer, public Subject {
    public:
    Coordinate pos;
    int blockLevel;
    CellType type;
    Coordinate** squad;

    Cell(Coordinate pos);
    void restore();
    void set(CellType t, int bl, Coordinate** squad);
    void notifySubject();
};

#endif
