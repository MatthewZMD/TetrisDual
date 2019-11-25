#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>
#include "state.h"
#include "observer.h"

class Subject {
    public:
    State state;
    std::vector<std::shared_ptr<Observer>> observers;

    void attach(std::shared_ptr<Observer> o);
    void detach(std::shared_ptr<Observer> o);
    void notifyObservers();
};

#endif
