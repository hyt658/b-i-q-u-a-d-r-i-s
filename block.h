#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>

class Block {
    std::string type;
    bool heavy;
    std::vector<std::vector<int>> theBlock;

    public:
        virtual void rotate(bool clockwise) = 0;
        bool isHeavy();
        std::string getBlockType();
        bool isEmpty();
};

#endif
