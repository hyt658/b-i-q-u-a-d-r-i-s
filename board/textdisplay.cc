#include "textdisplay.h"
using std::to_string;
using std::cout;
using std::endl;

const int ROW = 18;
const int COL = 11;

TextDisplay::TextDisplay(Board* b1, Board* b2):
    b1{b1}, b2{b2} {}

void TextDisplay::draw(int hiScore) {
    string hi_score = to_string(hiScore);
    string b1_score = to_string(b1->getScore());
    string b1_level = to_string(b1->getLevel());
    string b2_score = to_string(b2->getScore());
    string b2_level = to_string(b2->getLevel());

    // the header
    string boardDisplay = 
    "HiScore:  " + hi_score + "                HiScore:  " + hi_score + "\n"
    "Score:    " + b1_score + "                Score:    " + b2_score + "\n"
    "Level:    " + b1_level + "                Level:    " + b2_level + "\n"
    "-----------"      +      "                -----------\n";

    // two boards
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            string cell = b1->printCell(i, j);
            if (cell == "empty") cell = " ";
            boardDisplay += cell;
        }
        boardDisplay += "                ";
        for (int j = 0; j < COL; ++j) {
            string cell = b2->printCell(i, j);
            if (cell == "empty") cell = " ";
        }
        boardDisplay += "\n";
    }
    boardDisplay = boardDisplay + "-----------" + "                -----------\n";

    // next block area
    vector<string> b1_next_block = b1->getNextBlock();
    vector<string> b2_next_block = b2->getNextBlock();
    for (int i = 0; i < 2; ++i) {
        boardDisplay += b1_next_block[i];
        boardDisplay += "                ";
        boardDisplay += b2_next_block[i];
        boardDisplay += "\n";
    }

    cout << boardDisplay << endl;
}
