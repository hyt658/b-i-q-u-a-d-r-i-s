#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class IBlock: public Block{
    public:
        IBlock(bool heavy1, bool heavy2, int lv);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) override;
};

#endif
