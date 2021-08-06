#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class IBlock : public Block {
    public:
        IBlock(bool isheavy);
        virtual void rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif
