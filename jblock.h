#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"
#include <string>

class JBlock:public Block {
    public:
        JBlock(bool isheavy);
        void rotate(bool clockwise) override;
};

#endif
