#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subject.h"

class Subject;

class Observer {
    public:
    virtual void notify(Subject& s) = 0;
};

#endif
