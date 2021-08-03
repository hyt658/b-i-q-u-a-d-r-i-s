#include "zblock.h"
#include "block.h"

ZBlock::ZBlock(bool isheavy): Block{"Z", isheavy} {
    vector<int> first;
    first.emplace_back(0);
    first.emplace_back(0);
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
    fourth.emplace_back(2);
    locations.emplace_back(fourth);
}

void ZBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if((locations[0][0] == locations[1][0] && clockwise) || (locations[0][0] != locations[1][0] && !clockwise)){
        tryRotate(-1, 1, 0, 0, -1, -1, 0, -1, board);
    }
    else {
        tryRotate(1, -1, 0, 0, 1, 1, 0, 1, board);
    }
}

