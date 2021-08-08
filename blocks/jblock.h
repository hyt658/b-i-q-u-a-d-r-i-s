#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class JBlock:public Block {
    public:
        JBlock(bool isheavy);
        virtual void rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif
