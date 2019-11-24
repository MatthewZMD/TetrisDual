#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subject.h"

class Observer {
    virtual void notify(Subject s) = 0;
};

#endif
