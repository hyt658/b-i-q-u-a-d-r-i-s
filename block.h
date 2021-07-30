#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>
#include "subject.h"
#include "observer.h"

class Block: public Subject, public Observer {
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
        virtual void rotate(bool clockwise) = 0;
        virtual void moveLeft() = 0;
        virtual void moveRight() = 0;
        std::string getBlockType();
        std::vector<std::vector<int>>& getLocation();
        bool isHeavy();
        bool isEmpty();
        void notify() override;
};

#endif
