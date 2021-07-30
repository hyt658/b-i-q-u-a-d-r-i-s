#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"
#include <string>

class SBlock:public Block {
    public:
        SBlock(bool isheavy);
        void rotate(bool clockwise) override;
};

#endif