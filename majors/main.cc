#include "biquadris.h"
using std::cin;
using std::cout;
using std::endl;
using std::stoi;
using std::fstream;

int main(int argc, char *argv[]) {
    int start_level = 0;
    int seed = 0;
    bool only_text = false;
    string path1 = "sequence1.txt";
    string path2 = "sequence2.txt";
    string usage = 
    "  Biquadirs is a Latinization of the game Tetris, expanded for two player competition. Run\n"
    "this program with no flag with start the game by the default setting. The default setting\n"
    "includes: showing both text and graphic, constant block-generating seed, reading \n"
    "sequence[1-2].txt in level 0 for player[1-2], and starting from level 0. Here are some\n"
    "avaliable flags for this program:\n\n"
    "  -text               : Run in text-only mode.\n"
    "  -help               : Display the usage of this program.\n"
    "  -seed xxx           : Sets the random number generator's seed to xxx.\n"
    "  -scriptfile1 <path> : Uses the file from <path> instead of sequence1.txt as a source\n" 
    "                        of blocks for level 0, for player 1.\n"
    "  -scriptfile2 <path> : Uses the file from <path> instead of sequence2.txt as a source\n" 
    "                        of blocks for level 0, for player 2.\n"
    "  -startlevel n       : Starts the game in level n. (1 <= n <= 4)";

    int i = 1;
    while (i < argc) {
        try {
            string flag = argv[i];
            if (flag == "-text") {
                only_text = true;
            } else if (flag == "-help") {
                cout << usage << endl;
            } else if (flag == "-seed") {
                string next = argv[i+1];
                seed = stoi(next);
                i += 1;
            } else if (flag == "-scriptfile1") {
                path1 = argv[i+1];
                // just test for file existence.
                fstream file;
                file.open(path1);
                if (!file.is_open()) {
                    cout << "File path(s) do(es) not exist. "
                         << "Use flag \"-help\" for help." << endl;
                    return 0;
                } else {
                    file.close();
                }
                i += 1;
            } else if (flag == "-scriptfile2") {
                path2 = argv[i+1];
                // just test for file existence.
                fstream file;
                file.open(path2);
                if (!file.is_open()) {
                    cout << "File path(s) do(es) not exist. " 
                         << "Use flag \"-help\" for help." << endl;
                    return 0;
                } else {
                    file.close();
                }
                i += 1;
            } else if (flag == "-startlevel") {
                string next = argv[i+1];
                start_level = stoi(next);
                if (start_level > 4 || start_level < 0) {
                    cout << "Invalid level(s). "
                         << "Use flag \"-help\" for help." << endl;
                    return 0;
                }
                i += 1;
            } else {
                cout << "Unknown flag(s). Use flag \"-help\" for help." << endl;
                return 0;
            }
        } catch (...) {
            cout << "Invalid usage of the flag(s). "
                 << "Use flag \"-help\" for help." << endl;
            return 0;
        }
        ++i;
    }


    while (true) {
        Biquadris game;
        game.setup(start_level, seed, path1, path2, only_text);
        if (game.play() == 0) {
            break;
        }
    }
    return 0;
}
