#include "level_three.h"

Level3::Level3(int n, int seed): Level{n, true} {
    srand(seed);
}

Block* Level3::createCertainBlock(std::string type, Observer* board) {
    Block *NB;
    if (type == "I") {
        NB = new IBlock(lv_heavy, debuff_heavy, 3);
    } else if (type == "J") {
        NB = new JBlock(lv_heavy, debuff_heavy, 3);
    } else if (type == "L") {
        NB = new LBlock(lv_heavy, debuff_heavy, 3);
    } else if (type == "O") {
        NB = new OBlock(lv_heavy, debuff_heavy, 3);
    } else if (type == "S") {
        NB = new SBlock(lv_heavy, debuff_heavy, 3);
    } else if (type == "T") {
        NB = new TBlock(lv_heavy, debuff_heavy, 3);
    } else if (type == "Z") {
        NB = new ZBlock(lv_heavy, debuff_heavy, 3);
    }
    NB->attach(board);
    return NB;
}

Block* Level3::createRandBlock(Observer* board) {
    int ranum = rand() % (9-1+1) + 1;    // rand num in [1, 9]
    Block *NB;
    if (ranum == 1) {
        NB = createCertainBlock("I", board);
    } else if (ranum == 2) {
        NB = createCertainBlock("J", board);
    } else if (ranum == 3) {
        NB = createCertainBlock("L", board);
    } else if (ranum == 4) {
        NB = createCertainBlock("O", board);
    } else if (ranum == 5 || ranum == 6) {
        NB = createCertainBlock("S", board);
    } else if (ranum == 7) {
        NB = createCertainBlock("T", board);
    } else if (ranum == 8 || ranum == 9) {
        NB = createCertainBlock("Z", board);
    }
    return NB;
}
