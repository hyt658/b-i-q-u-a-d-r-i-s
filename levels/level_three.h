#ifndef __LEVEL_THREE_H__
#define __LEVEL_THREE_H__
#include "level.h"
#include <string>

class Level3:public Level {
    public:
        Level3(int n);
        Block* createRandBlock(Observer* board) override;
        Block* createCertainBlock(std::string type, Observer* board) override;
};

#endif