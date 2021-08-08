#include "level_three.h"
#include "level.h"

Level3::Level3(int n): Level{n} {}

Block* Level3::createCertainBlock(std::string type, Observer* board) {
      Block *NB;
   if (type == I) {
      Block *NB = new IBlock(true);
   } else if (type == J) {
      Block *NB = new JBlock(true);
   } else if (type == L) {
      Block *NB = new LBlock(true);
   } else if (type == O) {
      Block *NB = new OBlock(true);
   } else if (type == S) {
      Block *NB = new SBlock(true);
   } else if (type == T) {
      Block *NB = new TBlock(true);
   } else if (type == Z) {
      Block *NB = new ZBlock(true);
   } else {
      throw("WRONG COMMAND");
   }
   NB->attach(board);
   return NB;
}

Block* Level3::createRandBlock(Observer* board) {
   int ranum = (rand() % (9-1+1))+ 1;
   Block *NB;
   if (ranum == 1) {
      NB = createCertainBlock(I, board);
   } else if (ranum == 2) {
      NB = createCertainBlock(J, board);
   } else if (ranum == 3) {
      NB = createCertainBlock(L, board);
   } else if (ranum == 4) {
      NB = createCertainBlock(O, board);
   } else if (ranum == 5 || ranum == 6) {
      NB = createCertainBlock(S, board);
   } else if (ranum == 7) {
      NB = createCertainBlock(T, board);
   } else if (ranum == 8 || ranum == 9) {
      NB = createCertainBlock(Z, board);
   } else {
      throw("WRONG COMMAND");
   }
   return NB;
}