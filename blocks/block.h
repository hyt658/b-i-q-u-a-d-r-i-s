#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>
#include "../subject+observer/observer.h"
#include "../subject+observer/subject.h"
#include "../board/cell.h"

using std::string;
using std::vector;

/*
    1. Block is the observer of Cell:
        A Block can be the observer of multiple Cells, but each Cell has 
        one subject Block. Once a Cell is empty, it will notify its
        observer Block (the one it belongs to) and this Block will erase
        the Cell inside.
    2. Block is also the Subject of Board:
        Once Block has no Cells, it will notify the Board it belongs to,
        and this Board will increase the score.
*/

class Block: public Subject, public Observer {
    protected:
        int generateLv;
        string type;
        bool level_heavy;
        bool debuff_heavy;
        bool isdropped = false;
        vector<vector<int>> locations;

    public:
        Block(string new_type, bool heavy1, bool heavy2, int lv);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) = 0;
        bool moveLeft(vector<vector<Cell>> board, int multiplier);
        bool moveRight(vector<vector<Cell>> board, int multiplier);
        bool down(vector<vector<Cell>> board, int multiplier);
        bool drop(vector<vector<Cell>> board);
        string getBlockType();
        vector<vector<int>> getLocation();
        bool isEmpty();
        bool isFull(int idx, int a, int b, vector<vector<Cell>> board);
        void notify(int n=0, int m=0) override;
        void notifyObservers() override;
        bool tryRotate(int a, int b, int c, int d, int e, int f, int g, int h, vector<vector<Cell>> board);
        bool isDropped();
        bool contain(int idx, int ver, int hor);
};

#endif
