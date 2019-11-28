#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>
#include "state.h"
#include "coordinate.h"
#include "info.h"

class Observer;

class Subject {
    public:
    // TODO: Rewrite the state.h class!!
    //TextInfo textInfo; // TODO: the class data transmission between TextDisplay and Board
    //CellInfo cellInfo; // TODO: the class data transmission bettween ceel with cell and cell with board

    // OR we can separate Subject class into dedicated Subject class for CellInfo and TextInfo,
    // otherwise notifyObservers() can be a problem

    std::vector<std::shared_ptr<Observer>> observers;
    virtual std::vector<std::vector<Cell>> getTestInfo();
    void attach(Observer* o);
    void notifyObservers();
    virtual Info& getInfo() = 0;
    virtual State& getState() = 0;
};

#endif
