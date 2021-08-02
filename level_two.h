#ifndef __LEVEL_TWO_H__
#define __LEVEL_TWO_H__
#include "level.h"
#include <string>

class Level2:public Level {
    public:
        Level2(int n);
        Block* createRandBlock(Board* board) override;
        Block* createCertainBlock(std::string type, Board* board) override;
};

#endif