#ifndef __LEVEL_ZERO_H__
#define __LEVEL_ZERO_H__
#include "level.h"
#include <string>
#include <fstream>
#include <iostream>

class Level0:public Level {
    string path;
    std::ifstream infile;
    int count;
    public:
        Level0(int n, string path);
        Block* createRandBlock(Board* board) override;
        Block* createCertainBlock(std::string type, Board* board) override;
};

#endif