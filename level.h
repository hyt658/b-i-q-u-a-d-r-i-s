#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "block.h"

class Level {
    int lv;

    public:
        virtual Block* createRandBlock(Board* board) = 0;
        virtual Block* createCertainBlock(std::string type, Board* board) = 0;
        int getlevel();
};

#endif