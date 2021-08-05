#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <memory>
#include <fstream>
#include <algorithm>
#include "test.h"
using namespace std;

class A {
    vector<vector<int>> v;
    public:
        A(int n) {
            for (int i = 0; i < 5; ++i) {
                vector<int> temp;
                for (int j = 0; j < 5; ++j) {
                    temp.emplace_back(n);
                }
                v.emplace_back(temp);
                temp.clear();
            }
        }
        vector<vector<int>>& getV() {
            return v;
        }
        void print() {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    cout << v[i][j] << endl;
                }
            }
        }
};

vector<string> func() {
    vector<string> next;
    next = {"TTT        ", " T         "};
    return next;
}

int main(int argc, char* argv[]) {
        int start_level = 0;
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

    if (argc == 2) {
        string flag = argv[1];
        if (flag == "-text") {
            // run with only text
        } else if (flag == "-help") {
            cout << usage << endl;
        } else {
            cout << "Unknown flag or inproper usage. "
                 << "Use flag \"-help\" to see the usage." << endl;
        }
    } else if (argc == 3) {
        string flag1 = argv[1];
        string flag2 = argv[2];
        if (flag1 == "-seed") {
            int seed = 0;
            try {
                seed = stoi(flag2);
            } catch (...) {
                cout << "Input put seed is not a number. "
                     << "Use flag \"-help\" to see the usage." << endl;
                return 0;
            }
        } else if (flag1 == "-scriptfile1") {
            path1 = flag2;
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
        } else if (flag1 == "-scriptfile2") {
            path2 = flag2;
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
        } else if (flag1 == "-startlevel") {
            try {
                start_level = stoi(flag2);
                if (start_level > 4 || start_level < 1) {
                    cout << "Invalid level. "
                         << "Use flag \"-help\" to see the usage." << endl;
                    return 0;
                }
            } catch (...) {
                cout << "Input is not a number. "
                     << "Use flag \"-help\" to see the usage." << endl;
                return 0;
            }
        } else {
            cout << "Unknown flag. Use flag \"-help\" to see the usage." << endl;
            return 0;
        }
    } else if (argc > 3) {
        cout << "Unknown flag. Use flag \"-help\" to see the usage." << endl;
        return 0;
    }
} 
