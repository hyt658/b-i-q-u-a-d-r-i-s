#include "lblock.h"
#include "block.h"
#include <iostream>

using std::vector;

LBlock::LBlock(bool heavy1, bool heavy2): Block{"L", heavy1, heavy2} {
    vector<int> point;
    point.emplace_back(0);
    point.emplace_back(2);
    locations.emplace_back(point);
    for(int i = 2; i >= 0; i--) {
        vector<int> position;
        position.emplace_back(1);
        position.emplace_back(i);
        locations.emplace_back(position);
    }
}

bool LBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if(clockwise) {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][1] + 1 == locations[1][1]) {
                bool success = tryRotate(1, 1, 2, 0, 1, -1, 0, -2, board);
                if(success && level_heavy) {
                    down(board);
                }
                return success;
            }
            else {
                bool success = tryRotate(-1, -1, -2, 0, -1, 1, 0, 2, board);
                if(success && level_heavy) {
                    down(board);
                }
                return success;
            }
        }
        else {
            if(locations[0][0] + 1 == locations[1][0]) {
                bool success = tryRotate(1, -1, 0, -2, -1, -1, -2, 0, board);
                if(success && level_heavy) {
                    down(board);
                }
                return success;
            }
            else {
                bool success = tryRotate(-1, 1, 0, 2, 1, 1, 2, 0, board);
                if(success && level_heavy) {
                    down(board);
                }
                return success;
            }
        }
    }
    else {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][1] + 1 == locations[1][1]) {
                bool success = tryRotate(1, -1, 0, -2, -1, -1, -2, 0, board);
                if(success && level_heavy) {
                    down(board);
                }
                return success;
            }
            else {
                bool success = tryRotate(-1, 1, 0, 2, 1, 1, 2, 0, board);
                if(success && level_heavy) {
                    down(board);
                }
                return success;
            }
        }
        else {
            if(locations[0][0] + 1 == locations[1][0]) {
                bool success = tryRotate(-1, -1, -2, 0, -1, 1, 0, 2, board);
                if(success && level_heavy) {
                    down(board);
                }
                return success;
            }
            else {
                bool success = tryRotate(1, 1, 2, 0, 1, -1, 0, -2, board);
                if(success && level_heavy) {
                    down(board);
                }
                return success;
            }
        }
    }
}
