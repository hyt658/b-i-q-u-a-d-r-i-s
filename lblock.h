#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"
#include <string>

class LBlock:public Block {
    public:
        LBlock(bool isheavy);
        void rotate(bool clockwise) override;
};

#endif