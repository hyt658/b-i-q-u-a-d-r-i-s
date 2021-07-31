#ifndef _BOARD_H_
#define _BOARD_H_
#include <iostream>
#include "cell.h"
#include "block.h"
#include "level.h"
#include "observer.h"

class Board: public Observer {
    int score;
    Level* lv;
    Block* curr_blcok;
    Block* next_block;
    std::vector<Block*> Blocks;
    std::vector<int> cellsPerRow;
    std::vector<std::vector<Cell>> theBoard;
    std::vector<std::string> debuffs;

    public:
        Board(int row, int col);
        int getScore();
        void setLevel(int n);
        void levelUp();
        void levelDown();
        void generateBlock();
        void assignNextBlock(std::string type);
        void controlBlock(std::string command);
        void checkCancel();
        void setDebuff(std::string type);
        void printNextBlock();
        void printCell(int row, int col);
        void notify(int n=0, int m=0) override;
        ~Board();
};

#endif