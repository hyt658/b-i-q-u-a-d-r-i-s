#ifndef _BOARD_H_
#define _BOARD_H_
#include "cell.h"
#include "block.h"
#include "level.h"

class Board {
    int score;
    Level lv;
    std::vector<std::vector<Cell>> theBoard;

    public:
        void setLevel(int n);
        void levelUp();
        void levelDown();
        void generateBlock();
        void setBlock(std::string type);
        void controlBlock();
        void checkCancel();
        void setDebuff(std::string type);
        void printNextBlock();
        int getScore();
        void printCell(int row, int col);
};

#endif