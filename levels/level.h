#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "../blocks/iblock.h"
#include "../blocks/jblock.h"
#include "../blocks/lblock.h"
#include "../blocks/oblock.h"
#include "../blocks/sblock.h"
#include "../blocks/tblock.h"
#include "../blocks/zblock.h"
#include "../majors/commands.h"

class Level {
    protected:
        int lv;
        int block_num;
        bool lv_heavy;
        bool debuff_heavy;

    public:
        Level(int n, bool heavy);
        int getlevel();
        void applyHeavy();
        int getBlockNum();
        void resetBlockNum();
        virtual Block* createRandBlock(Observer* board) = 0;
        virtual Block* createCertainBlock(std::string type, Observer* board) = 0;
        virtual ~Level() = default;
};

#endif
