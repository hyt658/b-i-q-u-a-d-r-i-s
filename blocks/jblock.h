#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"
#include <string>

using std::vector;

class JBlock:public Block {
    public:
        JBlock(bool heavy1, bool heavy2);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board) override;
};

#endif
