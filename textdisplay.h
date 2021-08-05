#ifndef _TEXT_DISPLAY_
#define _TEXT_DISPLAY_
#include "board.h"
using std::vector;

class TextDisplay {
    Board* b1;
    Board* b2;

    public:
        TextDisplay(Board* b1, Board* b2);
        void draw(int hiScore);
};

#endif;