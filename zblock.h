#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"
#include <string>

class ZBlock:public Block {
    public:
        ZBlock(bool isheavy);
        void rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif
