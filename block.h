#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>
#include "subject.h"
#include "observer.h"
#include "board.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

using std::vector;

class Block: public Subject, public Observer {
    protected:
        int generateLv;
        std::string type;
        bool heavy;
        std::vector<std::vector<int>> locations;
        /*
        1. Block是cell的observer：
            一个Block可以是多个Cell的observer，但每个Cell只有一个Subject Block。
            当Cell被设置成empty时，会call观察他的Block（其实就是他所在的Block）
            的notify()，让该Block内部的cell数量-1。推荐使用一个int变量去记录每个
            Block observe的Cell的数量。
        2. Block也是Board的subject:
            当Block的Cell数量为0的时候，会call观察他的Board的notiy()然后在Board
            里加分。加分你不用管，做好在Cell数量为0，call observerNotify()就行。
        */

    public:
        Block(std::string new_type, bool isheavy);
        virtual void rotate(bool clockwise, vector<vector<Cell>> board) = 0;
        void moveLeft(vector<vector<Cell>> board);
        void moveRight(vector<vector<Cell>> board);
        void down(vector<vector<Cell>> board);
        void drop(vector<vector<Cell>> board);
        std::string getBlockType();
        vector<vector<int>>& getLocation();
        bool isHeavy();
        bool isEmpty();
        void notify(int n=0, int m=0) override;
        void notifyObservers() override;
        bool isFull(int idx, int a, int b, vector<vector<Cell>> board);
        void tryRotate(int a, int b, int c, int d, int e, int f, int g, int h, vector<vector<Cell>> board);
};

#endif
