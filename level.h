#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "board.h"
#define H "H"
#define L "L"
#define I "I"
#define J "J"
#define O "O"
#define S "S"
#define T "T"
#define Z "Z"

class Level {
    int lv;

    public:
        Level(int n);
        virtual Block* createRandBlock(Board* board) = 0;
        virtual Block* createCertainBlock(std::string type, Board* board) = 0;
        int getlevel();
        void applyHeavy();
};

#endif