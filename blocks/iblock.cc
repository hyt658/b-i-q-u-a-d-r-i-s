#include "iblock.h"

IBlock::IBlock(bool heavy1, bool heavy2, int lv): Block{"I", heavy1, heavy2, lv} {
    for(int i = 0; i < 4; i++) {
        vector<int> position;
        position.emplace_back(3);
        position.emplace_back(i);
        locations.emplace_back(position);
    }
}

bool IBlock::rotate(bool clockwise, vector<vector<Cell>> board, int multiplier) {
    bool moved = false;
    bool success = true;
    for(int i = 0; i < multiplier && success; i++) {
        if(locations[0][0] == locations[1][0]) {
            success = tryRotate(-2, 1, -1, 0, 0, -1, 1, -2, board);
            if(success) {
                moved = true;
            }
        }
        else {
            success = tryRotate(2, -1, 1, 0, 0, 1, -1, 2, board);
            if(success) {
                moved = true;
            }
        }
    }
    if(level_heavy && moved) {
        down(board);
    }
    return moved;
}
