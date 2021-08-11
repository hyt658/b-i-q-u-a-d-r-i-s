#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class SBlock:public Block {
    public:
        SBlock(bool heavy1, bool heavy2);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif