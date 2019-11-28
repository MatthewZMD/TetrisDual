#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>
#include "state.h"
#include "coordinate.h"
#include "info.h"

class Observer;
class Cell;

class Subject {
    public:
    std::vector<std::shared_ptr<Observer>> observers;
    virtual std::vector<std::vector<Cell>> getTestInfo();
    void attach(std::shared_ptr<Observer> o);
    void notifyObservers();
    virtual Info& getInfo() = 0;
    virtual State& getState() = 0;
};

#endif
