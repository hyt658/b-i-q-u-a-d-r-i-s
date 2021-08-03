#ifndef _BIQUADRIS_H_
#define _BIQUADRIS_H_
#include "board.h"

class Board;

class Biquadris {
    Board b1, b2;
    int highScore;
    
    public:
        Biquadris();
        void setup();   // set up two boards for two player
        int play();     // play the game. After one game end, return 1 
                        //   if want to replay a new game, return 0 if 
                        //   just want to quit 
};

#endif