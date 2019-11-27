#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>
#include "state.h"
#include "coordinate.h"

class Observer;

class Subject {
    public:
    // TODO: Rewrite the state.h class!!
    //TextInfo textInfo; // TODO: the class data transmission between TextDisplay and Board
    //CellInfo cellInfo; // TODO: the class data transmission bettween ceel with cell and cell with board

    // OR we can separate Subject class into dedicated Subject class for CellInfo and TextInfo,
    // otherwise notifyObservers() can be a problem
 
    std::vector<std::shared_ptr<Observer>> observers;
    void attach(std::shared_ptr<Observer> o);
    void detach(std::shared_ptr<Observer> o);
    void notifyObservers();

};

#endif
