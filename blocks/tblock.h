#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

class TBlock: public Block {
    public:
        TBlock(bool heavy1, bool heavy2, int lv);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) override;
};

#endif
