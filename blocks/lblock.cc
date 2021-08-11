#include "lblock.h"
#include "block.h"

using std::vector;

LBlock::LBlock(bool isheavy): Block{"L", isheavy} {
    for(int i = 0; i <= 2; i++) {
        vector<int> position;
        position.emplace_back(1);
        position.emplace_back(i);
        locations.emplace_back(position);
    }
    vector<int> point;
    point.emplace_back(2);
    point.emplace_back(0);
    locations.emplace_back(point);
}

bool LBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if(clockwise) {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][0] + 1 == locations[1][0]) {
                return tryRotate(1, 1, 2, 0, 1, -1, 0, -2, board);
            }
            else {
                return tryRotate(-1, -1, -2, 0, -1, 1, 0, 2, board);
            }
        }
        else {
            if(locations[0][1] + 1 == locations[1][1]) {
                return tryRotate(-1, 1, 0, 2, 1, 1, 2, 0, board);
            }
            else {
                return tryRotate(1, -1, 0, -2, -1, -1, -2, 0, board);
            }
        }
    }
    else {
        if(locations[0][0] == locations[0][1]) {
            if(locations[0][0] + 1 == locations[1][0]) {
                return tryRotate(-1, 1, 0, 2, 1, 1, 2, 0, board);
            }
            else {
                return tryRotate(1, -1, 0, -2, -1, -1, -2, 0, board);
            }
        }
        else {
            if(locations[0][1] + 1 == locations[1][1]) {
                return tryRotate(-1, -1, -2, 0, -1, 1, 0, 2, board);
            }
            else {
                return tryRotate(1, 1, 2, 0, 1, -1, 0, -2, board);
            }
        }
    }
}
