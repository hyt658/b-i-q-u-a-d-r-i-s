#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

class TBlock: public Block {
    public:
        TBlock(bool isheavy);
        virtual void rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif
