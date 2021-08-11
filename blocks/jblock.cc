#include "jblock.h"
#include "block.h"
#include <iostream>

using std::vector;

JBlock::JBlock(bool isheavy): Block{"J", isheavy} {
    vector<int> point;
    point.emplace_back(0);
    point.emplace_back(0);
    locations.emplace_back(point);
    for(int i = 0; i <= 2; i++) {
        vector<int> position;
        position.emplace_back(1);
        position.emplace_back(i);
        locations.emplace_back(position);
    }
}

bool JBlock::rotate(bool clockwise, vector<vector<Cell>> board) {
    bool success;
    if(clockwise) {
        if(locations[0][0] == locations[1][0]) {
            if(locations[0][0] + 1 == locations[1][0]) {
                success = tryRotate(-1, -1, 0, -2, 1, -1, -2, 0, board);
                std::cout<<success<<std::endl;
                return success;
            }
            else {
                success= tryRotate(1, 1, 0, 2, -1, 1, 2, 0, board);
                std::cout<<success<<std::endl;
                return success;
            }
        }
        else {
            if(locations[0][1] + 1 == locations[1][1]) {
                success= tryRotate(1, -1, 2, 0, 1, 1, 0, 2, board);
                std::cout<<success<<std::endl;
                return success;
            }
            else {
                success= tryRotate(-1, 1, -2, 0, -1, -1, 0, -2, board);
                std::cout<<success<<std::endl;
                return success;
            }
        }
    }
    else {
        if(locations[0][0] == locations[0][1]) {
            if(locations[0][0] + 1 == locations[1][0]) {
                success= tryRotate(-1, 1, -2, 0, -1, -1, 0, -2, board);
                std::cout<<success<<std::endl;
                return success;
            }
            else {
                success= tryRotate(1, -1, 2, 0, 1, 1, 0, 2, board);
                std::cout<<success<<std::endl;
                return success;
            }
        }
        else {
            if(locations[0][1] + 1 == locations[1][1]) {
                success= tryRotate(1, 1, 0, 2, -1, 1, -2, 0, board);
                std::cout<<success<<std::endl;
                return success;
            }
            else {
                success= tryRotate(-1, -1, 0, -2, 1, -1, -2, 0, board);
                std::cout<<success<<std::endl;
                return success;
            }
        }
    }
}
