#include "lblock.h"
#include <iostream>

using std::vector;

LBlock::LBlock(bool heavy1, bool heavy2, int lv): Block{"L", heavy1, heavy2, lv} {
    vector<int> point;
    point.emplace_back(3);
    point.emplace_back(2);
    locations.emplace_back(point);
    for(int i = 2; i >= 0; i--) {
        vector<int> position;
        position.emplace_back(4);
        position.emplace_back(i);
        locations.emplace_back(position);
    }
}

bool LBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    bool moved = false;
    bool success = true;
    if(clockwise) {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][1] + 1 == locations[1][1]) {
                success = tryRotate(1, 1, 2, 0, 1, -1, 0, -2, board);
                if(success) {
                    moved = true;
                }
            }
            else {
                success = tryRotate(-1, -1, -2, 0, -1, 1, 0, 2, board);
                if(success) {
                    moved = true;
                }
            }
        }
        else {
            if(locations[0][0] + 1 == locations[1][0]) {
                success = tryRotate(1, -1, 0, -2, -1, -1, -2, 0, board);
                if(success) {
                    moved = true;
                }
            }
            else {
                success = tryRotate(-1, 1, 0, 2, 1, 1, 2, 0, board);
                if(success) {
                    moved = true;
                }
            }
        }
    }
    else {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][1] + 1 == locations[1][1]) {
                success = tryRotate(1, -1, 0, -2, -1, -1, -2, 0, board);
                if(success) {
                    moved = true;
                }
            }
            else {
                success = tryRotate(-1, 1, 0, 2, 1, 1, 2, 0, board);
                if(success) {
                    moved = true;
                }
            }
        }
        else {
            if(locations[0][0] + 1 == locations[1][0]) {
                success = tryRotate(-1, -1, -2, 0, -1, 1, 0, 2, board);
                if(success) {
                    moved = true;
                }
            }
            else {
                success = tryRotate(1, 1, 2, 0, 1, -1, 0, -2, board);
                if(success) {
                    moved = true;
                }
            }
        }
    }
    if(level_heavy && moved) {
        down(board);
    }
    return moved;
}
