#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class LBlock:public Block {
    public:
        LBlock(bool heavy1, bool heavy2, int lv);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif