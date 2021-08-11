#include "iblock.h"

IBlock::IBlock(bool heavy1, bool heavy2): Block{"I", heavy1, heavy2} {
    for(int i = 0; i < 4; i++) {
        vector<int> position;
        position.emplace_back(0);
        position.emplace_back(i);
        locations.emplace_back(position);
    }
}

bool IBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    if(locations[0][0] == locations[1][0]) {
        bool success = tryRotate(-2, 1, -1, 0, 0, -1, 1, -2, board);
        if(success && level_heavy) {
            down(board);
        }
        return success;
    }
    else {
        bool success = tryRotate(2, -1, 1, 0, 0, 1, -1, 2, board);
        if(success && level_heavy) {
            down(board);
        }
        return success;
    }
}
