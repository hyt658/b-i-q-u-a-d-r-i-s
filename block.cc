#include "block.h"

Block::Block(std::string new_type, bool isheavy) : type{new_type}, heavy{isheavy} {}

bool Block::isHeavy() {
    return heavy;
}

std::string getBlockType() {
    return type;
}

bool isEmpty() {
    return theBlock.size() == 0;
}