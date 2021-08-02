#ifndef __LEVEL_ZERO_H__
#define __LEVEL_ZERO_H__
#include "level.h"
#include <string>

class Level0:public Level {
    public:
        Level0(int n);
        Block* createRandBlock(Board* board) override;
        Block* createCertainBlock(std::string type, Board* board) override;
};

#endif