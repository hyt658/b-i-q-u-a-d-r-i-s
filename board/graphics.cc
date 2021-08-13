#include <string.h>
#include <vector>
#include "graphics.h"

using namespace std;

const int ROW = 18;
const int COL = 11;

Graphics::Graphics(Board* b1, Board* b2) :
    b1{b1}, b2{b2}, w{new Xwindow(500, 500)} {
    }

void Graphics::Overwrite(int hiScore) {
    w->fillRectangle(0, 0, 500, 500, Xwindow::White);
    string hi_score = to_string(hiScore);
    string b1_score = to_string(b1->getScore());
    string b1_level = to_string(b1->getLevel());
    string b2_score = to_string(b2->getScore());
    string b2_level = to_string(b2->getLevel());
    // the header
    string HiScore = "HiScore: ";
    string Score = "Score: ";
    string Level = "Level: ";
    w->drawString(0, 10, HiScore+hi_score);
    w->drawString(0, 20, Score+b1_score);
    w->drawString(150, 20, Score+b2_score);
    w->drawString(0, 30, Level+b1_level);
    w->drawString(150, 30, Level+b2_level);
    w->fillRectangle(0, 40, 500, 110, Xwindow::White); 
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            string cell = b1->printCell(i, j);
            if(cell == "I") {
                w->fillRectangle(j * 10, (i+4)*10, 10, 10, Xwindow::Black);
            }
            if(cell == "J") {
                w->fillRectangle(j * 10, (i+4)*10, 10, 10, Xwindow::Red);
            }
            else if(cell == "L") {
                w->fillRectangle(j * 10, (i+4)*10, 10, 10, Xwindow::C);
            }
            else if(cell == "O") {
                w->fillRectangle(j * 10, (i+4)*10, 10, 10, Xwindow::Green);
            }
            else if(cell == "S") {
                w->fillRectangle(j * 10, (i+4)*10, 10, 10, Xwindow::Blue);
            }
            else if(cell == "T") {
                w->fillRectangle(j * 10, (i+4)*10, 10, 10, Xwindow::Purple);
            }
            else if(cell == "Z") {
                w->fillRectangle(j * 10, (i+4)*10, 10, 10, Xwindow::A);
            }
            else if(cell == "?") {
                w->drawString(j * 10, (i+4)*10, "?");
            }
        }
        for (int j = 0; j < COL; ++j) {
            string cell = b2->printCell(i, j);
            if(cell == "I") {
                w->fillRectangle(150 + j * 10, (i+4)*10, 10, 10, Xwindow::Black);
            }
            if(cell == "J") {
                w->fillRectangle(150 + j * 10, (i+4)*10, 10, 10, Xwindow::Red);
            }
            else if(cell == "L") {
                w->fillRectangle(150 + j * 10, (i+4)*10, 10, 10, Xwindow::C);
            }
            else if(cell == "O") {
                w->fillRectangle(150 + j * 10, (i+4)*10, 10, 10, Xwindow::Green);
            }
            else if(cell == "S") {
                w->fillRectangle(150 + j * 10, (i+4)*10, 10, 10, Xwindow::Blue);
            }
            else if(cell == "T") {
                w->fillRectangle(150 + j * 10, (i+4)*10, 10, 10, Xwindow::Purple);
            }
            else if(cell == "Z") {
                w->fillRectangle(150 + j * 10, (i+4)*10, 10, 10, Xwindow::A);
            }
            else if(cell == "?") {
                w->drawString(150 + j * 10, (i+4)*10, "?");
            }
        }
    }
        w->drawString(0, 230, "Next: ");
        vector<string> next = b1->getNextBlock();
        for(int m = 0; m < 2; m++) {
            for(int i = 0; i < 11; i++) {
                if(next[m].substr(i, 1) == "I") {
                    w->fillRectangle(i * 10, 240 + m *10, 10, 10, Xwindow::Black);
                }
                if(next[m].substr(i, 1) == "J") {
                    w->fillRectangle(i * 10, 240 + m *10, 10, 10, Xwindow::Red);
                }
                else if(next[m].substr(i, 1) == "L") {
                    w->fillRectangle(i * 10, 240 + m *10, 10, 10, Xwindow::C);
                }
                else if(next[m].substr(i, 1) == "O") {
                    w->fillRectangle(i * 10, 240 + m *10, 10, 10, Xwindow::Green);
                }
                else if(next[m].substr(i, 1) == "S") {
                    w->fillRectangle(i * 10, 240 + m *10, 10, 10, Xwindow::Blue);
                }
                else if(next[m].substr(i, 1) == "T") {
                    w->fillRectangle(i * 10, 240 + m *10, 10, 10, Xwindow::Purple);
                }
                else if(next[m].substr(i, 1) == "Z") {
                    w->fillRectangle(i * 10, 240 + m *10, 10, 10, Xwindow::A);
                }
            }
        }
        w->drawString(150, 230, "Next: ");
        next = b2->getNextBlock();
        for(unsigned int m = 0; m < 2; m++) {
            for(int i = 0; i < 11; i++) {
                if(next[m].substr(i, 1) == "I") {
                    w->fillRectangle(150 + i * 10, 240 + m *10, 10, 10, Xwindow::Black);
                }
                if(next[m].substr(i, 1) == "J") {
                    w->fillRectangle(150 + i * 10, 240 + m *10, 10, 10, Xwindow::Red);
                }
                else if(next[m].substr(i, 1) == "L") {
                    w->fillRectangle(150 + i * 10, 240 + m *10, 10, 10, Xwindow::C);
                }
                else if(next[m].substr(i, 1) == "O") {
                    w->fillRectangle(150 + i * 10, 240 + m *10, 10, 10, Xwindow::Green);
                }
                else if(next[m].substr(i, 1) == "S") {
                    w->fillRectangle(150 + i * 10, 240 + m *10, 10, 10, Xwindow::Blue);
                }
                else if(next[m].substr(i, 1) == "T") {
                    w->fillRectangle(150 + i * 10, 240 + m *10, 10, 10, Xwindow::Purple);
                }
                else if(next[m].substr(i, 1) == "Z") {
                    w->fillRectangle(150 + i * 10, 240 + m *10, 10, 10, Xwindow::A);
                }
            }
        }
}


Graphics::~Graphics() {
    delete w;
}

