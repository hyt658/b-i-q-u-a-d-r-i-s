#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"
#include <string>

class TBlock:public Block {
    public:
        TBlock(bool isheavy);
        void rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif
