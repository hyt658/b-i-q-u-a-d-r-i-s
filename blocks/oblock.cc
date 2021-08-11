#include "oblock.h"

using std::vector;

OBlock::OBlock(bool heavy1, bool heavy2, int lv): Block{"O", heavy1, heavy2, lv} {
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
    third.emplace_back(0);
    locations.emplace_back(third);
    vector<int> fourth;
    fourth.emplace_back(1);
    fourth.emplace_back(1);
    locations.emplace_back(fourth);
}

bool OBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if(level_heavy) {
        down(board);
    }
    return true;
}
