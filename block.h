#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>

class Block {
    protected:
        std::string type;
        bool heavy;
        std::vector<std::vector<int>> theBlock;

    public:
        Block(std::string new_type, bool isheavy);
        virtual void rotate(bool clockwise) = 0;
        bool isHeavy();
        std::string getBlockType();
        bool isEmpty();
};

#endif
