#include "tblock.h"
#include <vector>

using std::vector;

TBlock::TBlock(bool isheavy): Block{"I", isheavy} {
    vector<int> first;
    first.emplace_back(0);
    first.emplace_back(0);
    locations.emplace_back(first);
    vector<int> second;
    second.emplace_back(0);
    second.emplace_back(1);
    locations.emplace_back(second);
    vector<int> third;
    third.emplace_back(0);
    third.emplace_back(2);
    locations.emplace_back(third);
    vector<int> fourth;
    fourth.emplace_back(1);
    fourth.emplace_back(1);
    locations.emplace_back(fourth);
}

bool TBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if(clockwise) {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][0] + 1 == locations[1][0]) {
                return tryRotate(-1, 1, 0, 0, 1, -1, -1, -1, board);
            }
            else {
                return tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
            }
        }
        else {
            if(locations[0][1] + 1 == locations[1][1]) {
                return tryRotate(-1, 1, 0, 0, 1, 1, 1, -1, board);
            }
            else {
                return tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
            }
        }
    }
    else {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][0] + 1 == locations[1][0]) {
                return tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
            }
            else {
                return tryRotate(-1, 1, 0, 0, 1, 1, 1, -1, board);
            }
        }
        else {
            if(locations[0][1] + 1 == locations[1][1]) {
                return tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
            }
            else {
                return tryRotate(-1, 1, 0, 0, 1, -1, -1, -1, board);
            }
        }
    }
}