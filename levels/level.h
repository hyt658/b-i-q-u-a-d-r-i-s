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
        bool lv_heavy;
        bool debuff_heavy;

    public:
        Level(int n, bool heavy);
        virtual Block* createRandBlock(Observer* board) = 0;
        virtual Block* createCertainBlock(std::string type, Observer* board) = 0;
        int getlevel();
        void applyHeavy();
        virtual ~Level() = default;
};

#endif