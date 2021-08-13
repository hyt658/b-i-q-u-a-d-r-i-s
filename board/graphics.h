#ifndef _GRAPHICS_
#define _GRAPHICS_
#include "window.h"
#include "board.h"
#include "../blocks/block.h"
using std::vector;

class Graphics {
    Board* b1;
    Board* b2;
    Xwindow *w;
    public:
        Graphics(Board* b1, Board* b2);
        ~Graphics();
        void Overwrite(int hiScore);
        void printNext(Block *block, Board *b);
        void updateScore(int hiScore);
};


#endif