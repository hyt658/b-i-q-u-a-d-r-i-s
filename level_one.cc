#include "level_one.h"
#include "level.h"

Level1::Level1(int n): Level{n} {}

Block* Level1::createCertainBlock(std::string type, Board* board) {
      Block *NB;
   if (type == I) {
      Block *NB = new IBlock(false);
   } else if (type == J) {
      Block *NB = new JBlock(false);
   } else if (type == L) {
      Block *NB = new LBlock(false);
   } else if (type == O) {
      Block *NB = new OBlock(false);
   } else if (type == S) {
      Block *NB = new SBlock(false);
   } else if (type == T) {
      Block *NB = new TBlock(false);
   } else if (type == Z) {
      Block *NB = new ZBlock(false);
   } else {
      throw("WRONG COMMAND");
   }
   NB->attach(board);
   return NB;
}

Block* Level1::createRandBlock(Board* board) {
   int ranum = (rand() % (12-1+1))+ 1;
   Block *NB;
   if (ranum == 3 || ranum == 4) {
      NB = createCertainBlock(I, board);
   } else if (ranum == 5 || ranum == 6) {
      NB = createCertainBlock(J, board);
   } else if (ranum == 7 || ranum == 8) {
      NB = createCertainBlock(L, board);
   } else if (ranum == 9 || ranum == 10) {
      NB = createCertainBlock(O, board);
   } else if (ranum == 1) {
      NB = createCertainBlock(S, board);
   } else if (ranum == 11 || ranum == 12) {
      NB = createCertainBlock(T, board);
   } else if (ranum == 2) {
      NB = createCertainBlock(Z, board);
   } else {
      throw("WRONG COMMAND");
   }
   return NB;
}