#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "observer.h"

class Subject {
    protected:
        std::vector<Observer*> observers;

    public:
        Subject();
        void attach(Observer *o);
        void detach(Observer *o);   //估计用不上，先放着吧，最后删
        virtual void notifyObservers() = 0;
};

#endif