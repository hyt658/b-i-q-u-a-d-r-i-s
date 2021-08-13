#include "sblock.h"

using std::vector;

SBlock::SBlock(bool heavy1, bool heavy2, int lv): Block{"S", heavy1, heavy2, lv} {
    vector<int> first;
    first.emplace_back(3);
    first.emplace_back(2);
    locations.emplace_back(first);
    vector<int> second;
    second.emplace_back(3);
    second.emplace_back(1);
    locations.emplace_back(second);
    vector<int> third;
    third.emplace_back(4);
    third.emplace_back(1);
    locations.emplace_back(third);
    vector<int> fourth;
    fourth.emplace_back(4);
    fourth.emplace_back(0);
    locations.emplace_back(fourth);
}

bool SBlock::rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) {
    bool moved = false;
    bool success = true;
    for(int i = 0; i < multiplier && success; i++) {
        if(locations[0][0] == locations[1][0]) {
            success = tryRotate(-1, -2, 0, -1, -1, 0, 0, 1, board);
            if(success) {
                moved = true;
            }
        }
        else {
            success = tryRotate(1, 2, 0, 1, 1, 0, 0, -1, board);
            if(success) {
                moved = true;
            }
        }
    }
    if(level_heavy && moved) {
        down(board, 1);
    }
    return moved;
}