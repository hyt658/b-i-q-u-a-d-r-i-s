#include <fstream>
#include "biquadris.h"
#include "commands.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ifstream;


//////////////////////////////////////////////////////////////////////
// helper functions
//////////////////////////////////////////////////////////////////////

// go through a turn for given board (player)
// return 0 if one turn ends normally and go to next turn
// return 1 if the current players wants to restart the game
// return 2 if the player is lost 
int oneTurn(Board& curr, Board& oppnent) {
    istream* input = &cin;
    while (true) {
        cout << "Input your command:" << endl;
        string command;
        *input >> command;  
        if (command == LEFT || command == RIGHT || command == DOWN ||
            command == CLOCKWISE || command == COUNTER_CLOCKWISE ||
            command == DROP) {
            curr.controlBlock(command);
            if (command == DROP) break;
        } else if (command == SEQ) {
            string filename;
            cin >> filename;
            input = new ifstream{filename};
        } else if (command == RANDOM) {
            if (curr.getlevel() < 3) {
                cout << "This command is not suitable for current level." << endl;
            }
            //未完
        } else if (command == NO_RANDOM) {
            if (curr.getlevel() < 3) {
                cout << "This command is not suitable for current level." << endl;
            }
            //未完
        } else if (command == I || command == J || command == L ||
                   command == S || command == J || command == T) {
            curr.assignNextBlock(command);
        } else if (command == RESTART) {
            return 1;
        } else {
            cout << "Unknown command. Please try again." << endl;
        }
    }
    if (input != &cin) delete input;

    // check cancels
    if (curr.checkCancel() >= 2) {
        cout << "You have cleared more than one row. You earn a special attack!" << endl;
        cout << "Input the special attack you want to apply to your opponent:" << endl;
        while (true) {
            string debuff;
            cin >> debuff;
            if (debuff == BLIND || debuff == HEAVY || debuff == FORCE) {
                string force_block;
                if (debuff == FORCE) cin >> force_block;
                oppnent.setDebuff(debuff, force_block);
                break;
            } else {
                cout << "Unknown special attack. Please enter again." << endl;
            }
        }
    }

    if (curr.update() == 1) return 2;
    else return 0;
}

// n represents player. Ask about if player n agrees to restart the game
// return 0 means disagree, return 1 means agree
int checkRestart(int n) {
    cout << "Does player " << n << " agree to restart? (y/n)" << endl;
    string ans;
    cin >> ans;
    if (ans == "y") {
        return 1;
    } else if (ans == "n") {
        cout << "The game is continued." << endl;
    } else {
        cout << "Unknow answer. The game is continued." << endl;
    }
    return 0;
}


//////////////////////////////////////////////////////////////////////
// field methods
//////////////////////////////////////////////////////////////////////

Biquadris::Biquadris():
    b1{18, 11}, b2{18, 11}, highScore{0} {}

void Biquadris::setup() {
    int p1_lv, p2_lv;
    cout << "Enter the initial levels in order for player 1 and 2:" << endl;
    while (true) {
        try {
            cin >> p1_lv >> p2_lv ;
            break;
        } catch (...) {
            cout << "Inputs are not integers. Please try again." << endl;
        }
        // invalid levels
        if (p1_lv < 1 || p1_lv > 4 || p2_lv < 1 || p2_lv > 4) {
            cout << "Invalid input levels. Please try again." << endl;
        }
    }
    
    b1.init(p1_lv);
    b2.init(p2_lv);
}

int Biquadris::play() {
    int b1_result, b2_result;
    while (true) {
        // check if restart the game
        b1_result = oneTurn(b1, b2);
        if ((b1_result == 1) && (checkRestart(2) == 1)) {
            return 1;
        }
        b2_result = oneTurn(b2, b1);
        if ((b1_result == 1) && (checkRestart(1) == 1)) {
            return 1;
        }

        if (b1_result == 2) {
            cout << "player 1 is lost. The overlapped cell(s) are marked in X" << endl;
            break;
        } else if (b2_result == 2) {
            cout << "player 2 is lost. The overlapped cell(s) are marked in X" << endl;
            break;
        }
    }

    // after a game
    cout << "\nDo you want to play again? (y/n)" << endl;
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
