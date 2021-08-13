#ifndef __LEVEL_FOUR_H__
#define __LEVEL_FOUR_H__
#include "level.h"
#include <string>

class Level4:public Level {
    public:
        Level4(int n, int seed);
        shared_ptr<Block> createRandBlock(Observer* board) override;
        shared_ptr<Block> createCertainBlock(std::string type, Observer* board) override;
};

#endif
