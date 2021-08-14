#include "biquadris.h"
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;


//////////////////////////////////////////////////////////////////////
// helper functions + private methods
//////////////////////////////////////////////////////////////////////

// n represents player. Ask about if player n agrees to restart the game
// return 0 means disagree, return true means agree
bool checkRestart() {
    cout << "Does another player agree to restart? (y/n)" << endl;
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

void Biquadris::draw() {
    td->draw(highScore);
    if (!text) {
        graphic->Overwrite(highScore);
    }
}

// go through a turn for given board (player)
// return 0 if one turn ends normally and go to next turn
// return 1 if the current players wants to restart the game
// return 2 if the current player is lost 
// return 3 if the oppnent is lost (caused by force)
int Biquadris::oneTurn(Board& curr, Board& oppnent, istream** input) {
    draw();
    // control blocks
    bool end = false;
    int drop_times = 0;
    while (!end) {
        try {
            // multiple drops
            if (drop_times != 0) {
                end = curr.controlBlock("drop", 1);   // 1 is dummy parameter here
                drop_times -= 1;
                continue;
            }

            // receive commands normally
            int multiplier;
            string command;
            cout << "Input your command:" << endl;
            **input >> multiplier >> command;
            if (!((*input)->good())) {
                (*input)->clear();
                **input >> command;
                multiplier = 1;
            }
            command = commands.translateCommand(command);

            // response to the command
            if (command == "left" || command == "right" || command == "down" ||
                command == "clockwise" || command == "counterclockwise" ||
                command == "drop") {
                if (command == "drop" && multiplier != 1) {
                    drop_times = multiplier - 1;
                }
                end = curr.controlBlock(command, multiplier);  // end = true when dropped 
            } else if (command == "levelup") {
                curr.levelChange(true, multiplier); 
            } else if (command == "leveldown") {
                curr.levelChange(false, multiplier); 
            } else if (command == "sequence") {
                string filename;
                bool jump_out = false;
                while (true) {
                    **input >> filename;
                    infile.open(filename);
                    if (!infile.is_open()) {         
                        cout << "File path does not exist. Please re-enter the path. "
                             << "You do not need to enter \"sequence\" again.\n" 
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
                *input = &infile;
                (*input)->exceptions(ios::eofbit);
            } else if (command == "random") {
                if (curr.getLevel() < 3) {
                    cout << "This command is not suitable for the current level." << endl;
                    continue;
                }
                curr.randomGenerate(); 
            } else if (command == "norandom") {
                if (curr.getLevel() < 3) {
                    cout << "This command is not suitable for the current level." << endl;
                    continue;
                }
                bool jump_out = false;
                while (true) {
                    string path;
                    **input >> path;
                    try {
                        curr.fileGenerate(path);
                        break;
                    } catch (string&) {
                        cout << "Cannot find such file. Please re-enter the path. "
                             << "You do not need to enter \"norandom\" again.\n"
                             << "You also can input \"quit\" to skip." << endl;
                    }
                    if (path == "quit") {
                        jump_out = true;
                        break;
                    }
                }
                if (jump_out) continue; 
            } else if (command == "I" || command == "J" || command == "L" || command == "O" ||
                       command == "S" || command == "Z" || command == "T") {
                curr.assignNextBlock(command); 
            } else if (command == "restart") {
                if (checkRestart()) {
                    cout << "Game restarted.\n" << endl;
                    return 1;
                }
            } else if (command == "alias") {
                string old_command, new_command;
                while (true) {
                    **input >> old_command >> new_command;
                    if (old_command == "alias") {
                        cout << "You cannot overwrite the command alias." << endl;
                        break;
                    } else if (old_command == new_command) {
                        cout << "You cannot alias a command with itself." << endl;
                        break;
                    }
                    
                    int end = commands.alias(old_command, new_command);
                    if (end == 0) {
                        cout << "The original command is unknow. Please try again. "
                             << "You do not need to enter \"alias\" again." << endl;
                    } else if (end == 1) {
                        cout << "The new command has been aliased on other commands. "
                             << "Please try again.\n" 
                             << "You do not need to enter \"alias\" again." << endl;
                    } else {
                        break;
                    }
                }
            } else {
                cout << "Unknown command. Please try again." << endl;
                continue;
            }
            if (command != "sequence" && command != "alias") {
                draw();
            }
        } catch (ios::failure&) {
            string end_msg = "EOF quit game.";
            cout << end_msg << endl;
            throw end_msg;
        }
    }

    int cleaned_lines = curr.checkCancel();
    highScore = max(highScore, curr.getScore());
    if (cleaned_lines > 0) {
        draw();
    }
    // check cancels and trig special attack
    if (cleaned_lines >= 2) {
        cout << "You have cleared more than one row. You earn a special attack!" << endl;
        cout << "Input the special attack you want to apply to your opponent:" << endl;
        while (true) {
            string debuff;
            **input >> debuff;
            debuff = commands.translateCommand(debuff);
            if (debuff == "blind" || debuff == "heavy" || debuff == "force") {
                string force_block;
                while (debuff == "force") {
                    **input >> force_block;
                    force_block = commands.translateCommand(force_block);
                    if (force_block == "I" || force_block == "J" || force_block == "L" || force_block == "O" ||
                        force_block == "S" || force_block == "Z" || force_block == "T") {
                        break;
                    } else {
                        cout << "Unkown block. Please re-enter the forced block. "
                             << "You do not need to enter \"force\" again." << endl;
                    }
                }
                oppnent.setDebuff(debuff, force_block);
                if (debuff == "force" && !oppnent.placeNextBlock()) {
                    return 3;
                }
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


//////////////////////////////////////////////////////////////////////
// field methods
//////////////////////////////////////////////////////////////////////

Biquadris::Biquadris():
    b1{18, 11}, b2{18, 11}, highScore{0}    // 15 + 3 (reserved) rows, 11 colums
{
    td = make_shared<TextDisplay>(&b1, &b2);
    graphic = nullptr;
}     

void Biquadris::setup(int start_level, int seed, string path1, 
                      string path2, bool text_only) {
    text = text_only;
    b1.init(start_level, seed, path1);
    b2.init(start_level, seed, path2);
    if (!text) graphic = make_shared<Graphics>(&b1, &b2);
}

int Biquadris::play() {
    int b1_result, b2_result;
    istream* in = &cin;
    istream** input = &in;
    cin.exceptions(ios::eofbit);
    while (true) {
        try {
            // go through a trun for each player and check if someone 
            //   wants to restart the game
            cout << "Player 1's turn:" << endl;
            b1_result = oneTurn(b1, b2, input);    // throw a string when eof
            if (b1_result == 1) {
                return 1;
            } else if (b1_result == 2) {
                draw();
                cout << "player 1 is lost. The overlapped cell(s) is/are marked in -" << endl;
                break;
            } else if (b1_result == 3) {
                draw();
                cout << "player 2 is lost. The overlapped cell(s) is/are marked in -" << endl;
                break;
            }

            cout << "Player 2's turn:" << endl;
            b2_result = oneTurn(b2, b1, input);    // throw a string when eof
            if (b2_result == 1) {
                return 1;
            } else if (b2_result == 2) {
                draw();
                cout << "player 2 is lost. The overlapped cell(s) is/are marked in -" << endl;
                break;
            } else if (b1_result == 3) {
                draw();
                cout << "player 1 is lost. The overlapped cell(s) is/are marked in -" << endl;
                break;
            }
        } catch (string&) {
            // delete input if it's not cin
            //if (*input != &cin) delete *input;
            return 0;
        }
    }

    // delete input if it's not cin
    //if (*input != &cin) delete *input;    

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
    if (infile.is_open()) infile.close();
}