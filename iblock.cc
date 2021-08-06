#include "iblock.h"
#include "block.h"

IBlock::IBlock(bool isheavy): Block{"I", isheavy} {
    for(int i = 0; i < 4; i++) {
        vector<int> position;
        position.emplace_back(0);
        position.emplace_back(i);
        locations.emplace_back(position);
    }
}

void IBlock::rotate(bool clockwise, std::vector<std::vector<Cell>> board) {
    if((locations[0][0] == locations[1][0] && clockwise) || (locations[0][0] != locations[0][1] && !clockwise)) {
        tryRotate(-2, 1, -1, 0, 0, -1, 1, -2, board);
    }
    else {
        tryRotate(2, -1, 1, 0, 0, 1, -1, 2, board);
    }
}
