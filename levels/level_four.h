#ifndef __LEVEL_FOUR_H__
#define __LEVEL_FOUR_H__
#include "level.h"
#include <string>

class Level4:public Level {
    public:
        Level4(int n, int seed);
        Block* createRandBlock(Observer* board) override;
        Block* createCertainBlock(std::string type, Observer* board) override;
};

#endif