#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class TBlock:public Block {
    public:
        TBlock(bool isheavy);
        virtual void rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif
