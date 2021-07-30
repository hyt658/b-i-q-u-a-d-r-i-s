#include "subject.h"

Subject::Subject() {}

Subject::~Subject() {}

void Subject::attach( Observer *o ) {
    observers.emplace_back(o);
}



void Subject::notifyObservers() {
    for (auto ob : observers) {
        ob->notify();
    }
}