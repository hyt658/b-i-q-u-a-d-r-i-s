#include "biquadris.h"
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::stoi;
using std::fstream;

int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit|ios::failbit);
    int start_level = 0;
    string path1 = "sequence1.txt";
    string path2 = "sequence2.txt";
    string usage = 
    "No flag(s)          : Run with default setting. Both text and graphic are showed,\n"
    "                      seed is constant, reading sequence[1-2].txt for level 0 for\n"
    "                      player[1-2], and start from level 0.\n"
    "-text               : Run in text-only mode.\n"
    "-help               : See the usage of this program.\n"
    "-seed xxx           : Sets the random number generator’s seed to xxx.\n"
    "-scriptfile1 <path> : Uses the file from <path> instead of sequence1.txt as a source\n" 
    "                      of blocks for level 0, for player 1.\n"
    "-scriptfile2 <path> : Uses the file from <path> instead of sequence2.txt as a source\n" 
    "                      of blocks for level 0, for player 2.\n"
    "-startlevel n       : Starts the game in level n. (1 <= n <= 4)";

    if (argc == 2) {
        if (argv[1] == "-text") {
            // run with only text
        } else if (argv[1] == "-help") {
            cout << usage << endl;
        } else {
            cout << "Unknown flag. Use flag \"-help\" to see the usage." << endl;
        }
    } else if (argc == 3) {
        if (argv[1] == "-seed") {
            int seed = 0;
            try {
                seed = stoi(argv[2]);
            } catch (...) {
                cout << "Input put seed is not a number. "
                     << "Use flag \"-help\" to see the usage." << endl;
                return 0;
            }
        } else if (argv[1] == "-scriptfile1") {
            cin >> path1;
            // just test for file existence.
            fstream file;
            file.open(path1);
            if (!file.is_open()) {
                cout << "File path does not exist. "
                     << "Use flag \"-help\" to see the usage." << endl;
                return 0;
            } else {
                file.close();
            }
        } else if (argv[1] == "-scriptfile2") {
            cin >> path2;
            // just test for file existence.
            fstream file;
            file.open(path2);
            if (!file.is_open()) {
                cout << "File path does not exist. " 
                     << "Use flag \"-help\" to see the usage." << endl;
                return 0;
            } else {
                file.close();
            }
        } else if (argv[1] == "-startlevel") {
            try {
                cin >> start_level;
                if (start_level > 4 || start_level < 1) throw "Invalid level. ";
            } catch (ios::failure &) {
                cout << "Input is not a number. "
                     << "Use flag \"-help\" to see the usage." << endl;
                return 0;
            } catch (string& s) {
                cout << s << "Use flag \"-help\" to see the usage." << endl;
                return 0;
            }
        } else {
            cout << "Unknown flag. Use flag \"-help\" to see the usage." << endl;
            return 0;
        }
    } else {
        cout << "Unknown flag. Use flag \"-help\" to see the usage." << endl;
        return 0;
    }

    while (true) {
        Biquadris game;
        game.setup(start_level, path1, path2);
        if (game.play() == 0) {
            break;
        }
    }
    return 0;
}
