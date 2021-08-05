#ifndef _BIQUADRIS_H_
#define _BIQUADRIS_H_
#include "textdisplay.h"

//////////////////////////////////////////////////////////////////////
// Biquadris: the control class of the entire game, responsible for
//            IO and call corresponding methods
//  - setup(start_level, path1, path2): 
//      set up two boards for two player with start_level. If the 
//      start_level is 0, then generates block from reading files
//      from path1 and path2.
//  - play(): play the game. After one game end,  
//            return 1 if want to replay a new game, 
//            return 0 if just want to quit 
//////////////////////////////////////////////////////////////////////

class Biquadris {
    Board b1, b2;
    int highScore;
    TextDisplay* td;
    
    public:
        Biquadris();
        void setup(int start_level, string path1, string path2); 
        int play();  
        ~Biquadris();   
};

#endif