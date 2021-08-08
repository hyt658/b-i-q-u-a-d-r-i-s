#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class LBlock:public Block {
    public:
        LBlock(bool isheavy);
        virtual void rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif