#include "level.h"

Level::Level(int n, bool heavy): 
    lv{n}, lv_heavy{heavy}, debuff_heavy{false} {}

int Level::getlevel() {
    return lv;
}

void Level::applyHeavy() {
    debuff_heavy = true;
}
