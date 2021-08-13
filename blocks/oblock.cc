#include "oblock.h"

using std::vector;

OBlock::OBlock(bool heavy1, bool heavy2, int lv): Block{"O", heavy1, heavy2, lv} {
    vector<int> first;
    first.emplace_back(3);
    first.emplace_back(0);
    locations.emplace_back(first);
    vector<int> second;
    second.emplace_back(3);
    second.emplace_back(1);
    locations.emplace_back(second);
    vector<int> third;
    third.emplace_back(4);
    third.emplace_back(0);
    locations.emplace_back(third);
    vector<int> fourth;
    fourth.emplace_back(4);
    fourth.emplace_back(1);
    locations.emplace_back(fourth);
}

bool OBlock::rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) {
    if(level_heavy) {
        down(board);
    }
    return true;
}
