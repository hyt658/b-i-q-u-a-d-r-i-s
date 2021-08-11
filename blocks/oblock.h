#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class OBlock:public Block {
    public:
        OBlock(bool isheavy);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif