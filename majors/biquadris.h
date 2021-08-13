#ifndef _BIQUADRIS_H_
#define _BIQUADRIS_H_
#include "../board/textdisplay.h"
#include "../board/graphics.h"
#include "commands.h"

//////////////////////////////////////////////////////////////////////
// Biquadris: the control class of the entire game, responsible for
//            IO and call corresponding methods
//  - setup(start_level, path1, path2, only_text): 
//      set up two boards for two player with start_level. If the 
//      start_level is 0, then generates block from reading files
//      from path1 and path2. If only_text is true, then play the
//      in only text mode
//  - play(): play the game. After one game end,  
//            return 1 if want to replay a new game, 
//            return 0 if just want to quit 
//////////////////////////////////////////////////////////////////////

class Biquadris {
    Board b1, b2;
    int highScore;
    bool text;
    Commands commands;
    TextDisplay* td;
    Graphics* graphic;

    // private methods documentation see implementation file
    void draw();
    int oneTurn(Board& curr, Board& oppnent, std::istream** input);
    
    public:
        Biquadris();
        void setup(int start_level, int seed, string path1, string path2, bool only_text); 
        int play();  
        ~Biquadris();   
};

#endif