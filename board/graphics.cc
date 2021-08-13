#include "graphics.h"
#include <string.h>
#include "window.h"

using namespace std;

const int ROW = 18;
const int COL = 11;

Graphics::Graphics(Board* b1, Board* b2) :
    b1{b1}, b2{b2}, w{new Xwindow(500, 500)} {
    }

void Graphics::Overwrite(int hiScore) { 
    string hi_score = to_string(hiScore);
    string b1_score = to_string(b1->getScore());
    string b1_level = to_string(b1->getLevel());
    string b2_score = to_string(b2->getScore());
    string b2_level = to_string(b2->getLevel());
    w->fillRectangle(0, 0, 500, 500, Xwindow::White);
    // the header
    string HiScore = "HiScore: ";
    string Score = "Score: ";
    string Level = "Level: ";
    string Bound = "--------------------------------------------               --------------------------------------------";
    w->drawString(0, 10, HiScore+hi_score);
    w->drawString(0, 20, Score+b1_score);
    w->drawString(300, 20, Score+b2_score);
    w->drawString(0, 30, Level+b1_level);
    w->drawString(300, 30, Level+b2_level);
    w->drawString(0, 40, Bound);
    // two boards
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            string cell = b1->printCell(i, j);
            if (cell == "empty") {
                w->fillRectangle(j * 20, (i+2)*20, 20, 20, Xwindow::White);
            }
        }
        for (int j = 0; j < COL; ++j) {
            string cell = b2->printCell(i, j);
            if (cell == "empty") {
                w->fillRectangle(60 + j * 20, (i+2)*20, 20, 20, Xwindow::White);
            }
        }
    }
    w->drawString(0, 410, Bound);
}

Graphics::~Graphics() {
    delete w;
}
