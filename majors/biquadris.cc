#include "biquadris.h"
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ifstream;
using std::max;


//////////////////////////////////////////////////////////////////////
// helper functions
//////////////////////////////////////////////////////////////////////

// go through a turn for given board (player)
// return 0 if one turn ends normally and go to next turn
// return 1 if the current players wants to restart the game
// return 2 if the current player is lost 
// return 3 if the oppnent is lost (caused by force)
int oneTurn(Board& curr, Board& oppnent, int* highScore, TextDisplay* td) {
    ifstream infile;
    istream* input = &cin;
    cin.exceptions(ios::eofbit|ios::failbit);
    infile.exceptions(ios::eofbit|ios::failbit);
    td->draw(*highScore); 
    // control blocks
    while (true) {
        try {
            cout << "Input your command:" << endl;
            string command;
            *input >> command;  
            if (command == LEFT || command == RIGHT || command == DOWN ||
                command == CLOCKWISE || command == COUNTER_CLOCKWISE ||
                command == DROP) {
                curr.controlBlock(command); 
                td->draw(*highScore);
                if (command == DROP) {break;}    // end of control  
            } else if (command == SEQ) {
                bool jump_out = false;
                while (true) {
                    string filename;
                    cin >> filename;
                    infile.open(filename);
                    if (!infile.is_open()) {         
                        cout << "File path does not exist. Please re-enter the path. "
                             << "You do not need to enter " << SEQ << " again.\n" 
                             << "You also can input \"quit\" to skip." << endl;
                    } else {
                        break;
                    }

                    if (filename == "quit") {
                        jump_out = true;
                        break;
                    }
                }
                if (jump_out) continue;
                input = &infile;
            } else if (command == RANDOM) {
                if (curr.getLevel() < 3) {
                    cout << "This command is not suitable for the current level." << endl;
                    continue;
                }
                curr.randomGenerate();
                td->draw(*highScore); 
            } else if (command == NO_RANDOM) {
                if (curr.getLevel() < 3) {
                    cout << "This command is not suitable for the current level." << endl;
                    continue;
                }
                bool jump_out = false;
                while (true) {
                    string path;
                    cin >> path;
                    try {
                        curr.fileGenerate(path);
                        break;
                    } catch (string&) {
                        cout << "Cannot find such file. Please re-enter the path. "
                             << "You do not need to enter " << NO_RANDOM << " again.\n"
                             << "You also can input \"quit\" to skip." << endl;
                    }
                    if (path == "quit") {
                        jump_out = true;
                        break;
                    }
                }
                if (jump_out) continue;
                td->draw(*highScore); 
            } else if (command == I || command == J || command == L || command == O ||
                       command == S || command == J || command == T ) {
                curr.assignNextBlock(command);
                td->draw(*highScore); 
            } else if (command == RESTART) {
                return 1;
            } else {
                cout << "Unknown command. Please try again." << endl;
            }
        } catch (ios::failure&) {
            string end_msg = "EOF quit game.";
            cout << end_msg << endl;
            throw end_msg;
        }
    }
    if (input != &cin) infile.close();    // close the infile if it is opened

    int cleaned_lines = curr.checkCancel();
    *highScore = max(*highScore, curr.getScore());
    if (cleaned_lines > 0) {
        td->draw(*highScore); 
    }
    // check cancels and trig special attack
    if (cleaned_lines >= 2) {
        cout << "You have cleared more than one row. You earn a special attack!" << endl;
        cout << "Input the special attack you want to apply to your opponent:" << endl;
        while (true) {
            string debuff;
            cin >> debuff;
            if (debuff == BLIND || debuff == HEAVY || debuff == FORCE) {
                string force_block;
                while (debuff == FORCE) {
                    cin >> force_block;
                    if (force_block == I || force_block == J || force_block == L ||
                        force_block == S || force_block == Z || force_block == T) {
                        break;
                    } else {
                        cout << "Unkown block. Please re-enter the forced block. "
                             << "You do not need to enter " << FORCE << " again." << endl;
                    }
                }
                oppnent.setDebuff(debuff, force_block);
                td->draw(*highScore); 
                if (!oppnent.placeNextBlock()) return 3;
                break;
            } else {
                cout << "Unknown special attack. Please try again." << endl;
            }
        }
    }

    curr.update();
    if (curr.placeNextBlock()) return 0;
    else return 2;
}

// n represents player. Ask about if player n agrees to restart the game
// return 0 means disagree, return true means agree
bool checkRestart(int n) {
    cout << "Does player " << n << " agree to restart? (y/n)" << endl;
    string ans;
    cin >> ans;
    if (ans == "y") {
        return true;
    } else if (ans == "n") {
        cout << "The game is continued." << endl;
    } else {
        cout << "Unknow answer. The game is continued." << endl;
    }
    return false;
}


//////////////////////////////////////////////////////////////////////
// field methods
//////////////////////////////////////////////////////////////////////

Biquadris::Biquadris():
    b1{18, 11}, b2{18, 11}, highScore{0}    // 15 + 3 (extra) rows, 11 colums
{
    td = new TextDisplay{&b1, &b2};
}     

void Biquadris::setup(int start_level, string path1, string path2) {
    b1.init(start_level, path1);
    b2.init(start_level, path2);
}

int Biquadris::play() {
    int b1_result, b2_result;
    while (true) {
        try {
            // go through a trun for each player and check if someone 
            //   wants to restart the game
            cout << "Player 1's turn:" << endl;
            b1_result = oneTurn(b1, b2, &highScore, td);    // throw a string when eof
            if ((b1_result == 1) && (checkRestart(2) == true)) {
                return 1;
            }

            cout << "Player 2's turn:" << endl;
            b2_result = oneTurn(b2, b1, &highScore, td);    // throw a string when eof
            if ((b2_result == 1) && (checkRestart(1) == true)) {
                return 1;
            }

            // check if someone is lost
            if (b1_result == 2 || b2_result == 3) {
                cout << "player 1 is lost. The overlapped cell(s) is/are marked in X" << endl;
                break;
            } else if (b2_result == 2 || b1_result == 3) {
                cout << "player 2 is lost. The overlapped cell(s) is/are marked in X" << endl;
                break;
            }
        } catch (string&) {
            return 0;
        }
    }

    // after a game
    cout << "Do you want to play again? (y/n)" << endl;
    string ans;
    cin >> ans;
    if (ans == "y") {
        return 1;
    } else if (ans == "n") {
        return 0;
    } else {
        cout << "Unknow answer. Program is terminated." << endl;
        return 0;
    }
}

Biquadris::~Biquadris() {
    delete td;
}
