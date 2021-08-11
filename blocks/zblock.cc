#include "zblock.h"

using std::vector;

ZBlock::ZBlock(bool heavy1, bool heavy2): Block{"Z", heavy1, heavy2} {
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

bool ZBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if(locations[0][0] == locations[1][0]){
        bool success = tryRotate(-1, 1, 0, 0, -1, -1, 0, -1, board);
        if(success && level_heavy) {
            down(board);
        }
        return success;
    }
    else {
        bool success = tryRotate(1, -1, 0, 0, 1, 1, 0, 1, board);
        if(success && level_heavy) {
            down(board);
        }
        return success;
    }
}

