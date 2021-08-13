#ifndef __LEVEL_THREE_H__
#define __LEVEL_THREE_H__
#include "level.h"
#include <string>

class Level3:public Level {
    public:
        Level3(int n, int seed);
        shared_ptr<Block> createRandBlock(Observer* board) override;
        shared_ptr<Block> createCertainBlock(std::string type, Observer* board) override;
};

#endif
