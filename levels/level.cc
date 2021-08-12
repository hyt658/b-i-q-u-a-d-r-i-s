#include "level.h"

Level::Level(int n, bool heavy): 
    lv{n}, block_num{-1}, lv_heavy{heavy}, debuff_heavy{false} {}

int Level::getlevel() {
    return lv;
}

void Level::applyHeavy() {
    debuff_heavy = true;
}

int Level::getBlockNum() {
    return block_num;
}

void Level::resetBlockNum() {
    block_num = -1;
}