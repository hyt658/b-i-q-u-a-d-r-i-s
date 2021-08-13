#include "level_zero.h"
using namespace std;

Level0::Level0(int n, string path): Level{n, false}, path{path} {
    infile.open(path);
}

shared_ptr<Block> Level0::createCertainBlock(std::string type, Observer* board) {
    shared_ptr<Block> NB;
    if (type == "I") {
        NB = make_shared<IBlock> (lv_heavy, debuff_heavy, 0);
    } else if (type == "J") {
        NB = make_shared<JBlock> (lv_heavy, debuff_heavy, 0);
    } else if (type == "L") {
        NB = make_shared<LBlock> (lv_heavy, debuff_heavy, 0);
    } else if (type == "O") {
        NB = make_shared<OBlock> (lv_heavy, debuff_heavy, 0);
    } else if (type == "S") {
        NB = make_shared<SBlock> (lv_heavy, debuff_heavy, 0);
    } else if (type == "T") {
        NB = make_shared<TBlock> (lv_heavy, debuff_heavy, 0);
    } else if (type == "Z") {
        NB = make_shared<ZBlock> (lv_heavy, debuff_heavy, 0);
    }
    NB->attach(board);
    return NB;
}

shared_ptr<Block> Level0::createRandBlock(Observer* board) {
    string next;
    infile >> next;
    if (infile.eof()) {
        infile.close();
        infile.open(path);
        infile >> next;
    }
    shared_ptr<Block> NB = createCertainBlock(next, board);;
    return NB;
}

Level0::~Level0() {
    if (infile.is_open()) infile.close();
}
