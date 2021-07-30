#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"
#include <string>

class IBlock:public Block {
    public:
        IBlock(bool isheavy);
        void rotate(bool clockwise) override;
};

#endif
