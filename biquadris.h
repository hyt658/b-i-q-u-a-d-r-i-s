#ifndef _BIQUADRIS_H_
#define _BIQUADRIS_H_
#include "board.h"

class Board;

class Biquadris {
    Board b1, b2;
    int highScore;
    
    public:
        Biquadris();
        void setup();
        void play();
};

#endif