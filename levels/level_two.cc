#include "level_two.h"
#include "level.h"

Level2::Level2(int n): Level{n} {}

Block* Level2::createCertainBlock(std::string type, Observer* board) {
   Block *NB;
   if (type == I) {
      NB = new IBlock(false);
   } else if (type == J) {
      NB = new JBlock(false);
   } else if (type == L) {
      NB = new LBlock(false);
   } else if (type == O) {
      NB = new OBlock(false);
   } else if (type == S) {
      NB = new SBlock(false);
   } else if (type == T) {
      NB = new TBlock(false);
   } else if (type == Z) {
      NB = new ZBlock(false);
   } else {
      throw("WRONG COMMAND");
   }
   NB->attach(board);
   return NB;
}

Block* Level2::createRandBlock(Observer* board) {
   int ranum = (rand() % (7-1+1))+ 1;
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
   } else {
      throw("WRONG COMMAND");
   }
   return NB;
}