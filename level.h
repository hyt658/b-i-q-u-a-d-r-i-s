#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "block.h"

class Level {
    int lv;

    public:
        virtual Block createBlock() = 0;
        int getlevel();
};

#endif