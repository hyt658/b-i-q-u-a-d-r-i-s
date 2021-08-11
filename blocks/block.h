#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>
#include "../subject+observer/observer.h"
#include "../subject+observer/subject.h"
#include "../board/cell.h"

using std::string;
using std::vector;

class Block: public Subject, public Observer {
    protected:
        int generateLv;
        string type;
        int heavy;
        bool isdropped = false;
        vector<vector<int>> locations;
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
        Block(string new_type, bool isheavy);
        virtual bool rotate(bool clockwise, vector<vector<Cell>> board) = 0;
        bool moveLeft(vector<vector<Cell>> board);
        bool moveRight(vector<vector<Cell>> board);
        bool down(vector<vector<Cell>> board);
        void drop(vector<vector<Cell>> board);
        string getBlockType();
        vector<vector<int>> getLocation();
        bool isHeavy();
        bool isEmpty();
        bool isFull(int idx, int a, int b, vector<vector<Cell>> board);
        void notify(int n=0, int m=0) override;
        void notifyObservers() override;
        bool tryRotate(int a, int b, int c, int d, int e, int f, int g, int h, vector<vector<Cell>> board);
        bool isDropped();
        bool contain(int idx, int ver, int hor);
};

#endif
