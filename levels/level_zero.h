#ifndef __LEVEL_ZERO_H__
#define __LEVEL_ZERO_H__
#include "level.h"
#include <fstream>

class Level0: public Level {
    std::string path;
    std::ifstream infile;

    public:
        Level0(int n, string path);
        Block* createRandBlock(Observer* board) override;
        Block* createCertainBlock(std::string type, Observer* board) override;
        ~Level0();
};

#endif
