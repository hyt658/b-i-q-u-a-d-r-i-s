#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Observer {
    public:
        // parameter n and m are used when necessary
        virtual void notify(int n=0, int m=0) = 0;     
        virtual ~Observer() = default;
};

#endif
