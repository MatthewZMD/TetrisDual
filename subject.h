#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "state.h"
#include "observer.h"

class Subject {
    State state;
    std::vector<std::vector<Observer*>> observers;

    void attach(Observer* o);
    void detach(Observer* o);
    void notifyObservers();
};

#endif
