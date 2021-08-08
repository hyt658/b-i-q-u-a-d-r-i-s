#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class ZBlock:public Block {
    public:
        ZBlock(bool isheavy);
        virtual void rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif
