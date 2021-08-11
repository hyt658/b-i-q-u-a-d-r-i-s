#include "level_zero.h"
#include <fstream>
using namespace std;

Level0::Level0(int n, string path): Level{n}, path{path} {
    infile.open(path);
}

Block* Level0::createCertainBlock(std::string type, Observer* board) {
    Block *NB;
    if (type == I) {
        NB = new IBlock(heavy);
    } else if (type == J) {
        NB = new JBlock(heavy);
    } else if (type == L) {
        NB = new LBlock(heavy);
    } else if (type == O) {
        NB = new OBlock(heavy);
    } else if (type == S) {
        NB = new SBlock(heavy);
    } else if (type == T) {
        NB = new TBlock(heavy);
    } else if (type == Z) {
        NB = new ZBlock(heavy);
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
