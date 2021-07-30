#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"
#include <string>

class OBlock:public Block {
    public:
        OBlock(bool isheavy);
        void rotate(bool clockwise) override;
};

#endif