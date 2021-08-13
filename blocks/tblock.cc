#include "tblock.h"
#include <vector>

using std::vector;

TBlock::TBlock(bool heavy1, bool heavy2, int lv): Block{"I", heavy1, heavy2, lv} {
    vector<int> first;
    first.emplace_back(3);
    first.emplace_back(0);
    locations.emplace_back(first);
    vector<int> second;
    second.emplace_back(3);
    second.emplace_back(1);
    locations.emplace_back(second);
    vector<int> third;
    third.emplace_back(3);
    third.emplace_back(2);
    locations.emplace_back(third);
    vector<int> fourth;
    fourth.emplace_back(4);
    fourth.emplace_back(1);
    locations.emplace_back(fourth);
}

bool TBlock::rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) {
    bool moved = false;
    bool success = true;
    if(clockwise) {
        for(int i = 0; i < multiplier && success; i++) {
            if(locations[0][0] == locations[1][0]) {
                if(locations[0][1] + 1 == locations[1][1]) {
                    success = tryRotate(-1, 1, 0, 0, 1, -1, -1, -1, board);
                    if(success) {
                        moved = true;
                    }
                }
                else {
                    success = tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
                    if(success) {
                        moved = true;
                    }
                }
            }
            else {
                if(locations[0][0] + 1 == locations[1][0]) {
                    success = tryRotate(1, 1, 0, 0, -1, -1, -1, 1, board);
                    if(success) {
                        moved = true;
                    }
                }
                else {
                    success = tryRotate(-1, -1, 0, 0, 1, 1, 1, -1, board);
                    if(success) {
                        moved = true;
                    }
                }
            }
        }
    }
    else {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][1] + 1 == locations[1][1]) {
                success = tryRotate(1, 1, 0, 0, -1, -1, -1, 1, board);
                if(success) {
                    moved = true;
                }
            }
            else {
                success = tryRotate(-1, -1, 0, 0, 1, 1, 1, -1, board);
                if(success) {
                    moved = true;
                }
            }
        }
        else {
            if(locations[0][0] + 1 == locations[1][0]) {
                success = tryRotate(1, -1, 0, 0, -1, 1, 1, 1, board);
                if(success) {
                    moved = true;
                }
            }
            else {
                success = tryRotate(-1, 1, 0, 0, 1, -1, -1, -1, board);
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