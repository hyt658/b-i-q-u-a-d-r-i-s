#include "sblock.h"
#include "block.h"

using std::vector;

SBlock::SBlock(bool isheavy): Block{"S", isheavy} {
    vector<int> first;
    first.emplace_back(0);
    first.emplace_back(2);
    locations.emplace_back(first);
    vector<int> second;
    second.emplace_back(0);
    second.emplace_back(1);
    locations.emplace_back(second);
    vector<int> third;
    third.emplace_back(1);
    third.emplace_back(1);
    locations.emplace_back(third);
    vector<int> fourth;
    fourth.emplace_back(1);
    fourth.emplace_back(0);
    locations.emplace_back(fourth);
}

bool SBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if((locations[0][0] == locations[1][0] && clockwise) || (locations[0][0] != locations[1][0] && !clockwise)){
        return tryRotate(-1, -2, 0, -1, -1, 0, 0, 1, board);
    }
    else {
        return tryRotate(1, 2, 0, 1, 1, 0, 0, -1, board);
    }
}