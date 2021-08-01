#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"
#include <string>

class OBlock:public Block {
    public:
        OBlock(bool isheavy);
        void rotate(bool clockwise) override;
        void rotate(bool clockwise, vector<vector<Cell>> board) override;
        void notify(int n=0, int m=0) override;
};

#endif