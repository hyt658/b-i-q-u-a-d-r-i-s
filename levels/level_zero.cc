#include "level_zero.h"
#include <fstream>
using namespace std;

Level0::Level0(int n, string path): Level{n}, path{path} {
   (this->infile).open(this->path);
}

Block* Level0::createCertainBlock(std::string type, Observer* board) {
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

Block* Level0::createRandBlock(Observer* board) {
   string next;
   infile >> next;
   Block *NB;
   NB = createCertainBlock(next, board);
   return NB;
}
