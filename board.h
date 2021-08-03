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
        void init(int n);
        int getScore();
        void setLevel(int n);
        int getlevel();
        void levelUp();
        void levelDown();
        int update();
        void assignNextBlock(std::string type);
        void controlBlock(std::string command);
        int checkCancel();
        void setDebuff(std::string type);
        void printBoard();
        void notify(int n=0, int m=0) override;
        ~Board();
};

#endif