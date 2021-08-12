#include "level_zero.h"
using namespace std;

Level0::Level0(int n, string path): Level{n, false}, path{path} {
    infile.open(path);
}

Block* Level0::createCertainBlock(std::string type, Observer* board) {
    Block *NB;
    if (type == I) {
        NB = new IBlock(lv_heavy, debuff_heavy, 0);
    } else if (type == J) {
        NB = new JBlock(lv_heavy, debuff_heavy, 0);
    } else if (type == L) {
        NB = new LBlock(lv_heavy, debuff_heavy, 0);
    } else if (type == O) {
        NB = new OBlock(lv_heavy, debuff_heavy, 0);
    } else if (type == S) {
        NB = new SBlock(lv_heavy, debuff_heavy, 0);
    } else if (type == T) {
        NB = new TBlock(lv_heavy, debuff_heavy, 0);
    } else if (type == Z) {
        NB = new ZBlock(lv_heavy, debuff_heavy, 0);
    }
    NB->attach(board);
    return NB;
}

Block* Level0::createRandBlock(Observer* board) {
    string next;
    infile >> next;
    if (infile.eof()) {
        infile.close();
        infile.open(path);
        infile >> next;
    }
    Block *NB = createCertainBlock(next, board);;
    return NB;
}

Level0::~Level0() {
    if (infile.is_open()) infile.close();
}
