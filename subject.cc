#include "subject.h"

void Subject::attach(std::shared_ptr<Observer> o){
    observers.emplace_back(o);
}

void Subject::notifyObservers(){
    for (auto& ob : observers){
        ob->notify(*this);
    }
}
