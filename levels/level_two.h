#ifndef __LEVEL_TWO_H__
#define __LEVEL_TWO_H__
#include "level.h"
#include <string>

class Level2:public Level {
    public:
        Level2(int n);
        shared_ptr<Block> createRandBlock(Observer* board) override;
        shared_ptr<Block> createCertainBlock(std::string type, Observer* board) override;
};

#endif