#include "level_two.h"
#include "level.h"

Level2::Level2(int n): Level{n} {}

Block* Level2::createCertainBlock(std::string type, Observer* board) {
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

Block* Level2::createRandBlock(Observer* board) {
    int ranum = rand() % (7-1+1) + 1;   // rand num in [1, 7]
    Block *NB;
    if (ranum == 1) {
        NB = createCertainBlock(I, board);
    } else if (ranum == 2) {
        NB = createCertainBlock(J, board);
    } else if (ranum == 3) {
        NB = createCertainBlock(L, board);
    } else if (ranum == 4) {
        NB = createCertainBlock(O, board);
    } else if (ranum == 5) {
        NB = createCertainBlock(S, board);
    } else if (ranum == 6) {
        NB = createCertainBlock(T, board);
    } else if (ranum == 7) {
        NB = createCertainBlock(Z, board);
    }
    return NB;
}