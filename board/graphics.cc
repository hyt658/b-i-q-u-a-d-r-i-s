#include "graphics.h"
#include <string.h>
#include "window.h"
#include "../blocks/block.h"
#include <vector>

using namespace std;

const int ROW = 18;
const int COL = 11;

Graphics::Graphics(Board* b1, Board* b2) :
    b1{b1}, b2{b2}, w{new Xwindow(500, 500)} {
    }

void Graphics::Overwrite(int hiScore) { 
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
}

void Graphics::updateScore(int hiScore) {
    string hi_score = to_string(hiScore);
    string b1_score = to_string(b1->getScore());
    string b1_level = to_string(b1->getLevel());
    string b2_score = to_string(b2->getScore());
    string b2_level = to_string(b2->getLevel());
    w->fillRectangle(0, 0, 500, 40, Xwindow::White);
    // the header
    string HiScore = "HiScore: ";
    string Score = "Score: ";
    string Level = "Level: ";
    w->drawString(0, 10, HiScore+hi_score);
    w->drawString(0, 20, Score+b1_score);
    w->drawString(150, 20, Score+b2_score);
    w->drawString(0, 30, Level+b1_level);
    w->drawString(150, 30, Level+b2_level);
}

Graphics::~Graphics() {
    delete w;
}

void Graphics::printNext(Block *block, Board *b) {
    w->fillRectangle(0, 240, 500, 50, Xwindow::White);
    vector<vector<int>> locations = block->getLocation();
    if(b == b1) {
        w->drawString(0, 230, "Next: ");
        for(int i = 0; i < 4; i++) {
            if(block->getBlockType() == "I") {
                w->fillRectangle(locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Black);
            }
            if(block->getBlockType() == "J") {
                w->fillRectangle(locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Red);
            }
            else if(block->getBlockType() == "L") {
                w->fillRectangle(locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::C);
            }
            else if(block->getBlockType() == "O") {
                w->fillRectangle(locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Green);
            }
            else if(block->getBlockType() == "S") {
                w->fillRectangle(locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Blue);
            }
            else if(block->getBlockType() == "T") {
                w->fillRectangle(locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Purple);
            }
            else if(block->getBlockType() == "Z") {
                w->fillRectangle(locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::A);
            }
        }
    }
    else {
        w->drawString(150, 230, "Next: ");
        for(int i = 0; i < 4; i++) {
            if(block->getBlockType() == "I") {
                w->fillRectangle(150 + locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Black);
            }
            if(block->getBlockType() == "J") {
                w->fillRectangle(150 + locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Red);
            }
            else if(block->getBlockType() == "L") {
                w->fillRectangle(150 + locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::C);
            }
            else if(block->getBlockType() == "O") {
                w->fillRectangle(150 + locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Green);
            }
            else if(block->getBlockType() == "S") {
                w->fillRectangle(150 + locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Blue);
            }
            else if(block->getBlockType() == "T") {
                w->fillRectangle(150 + locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::Purple);
            }
            else if(block->getBlockType() == "Z") {
                w->fillRectangle(150 + locations[i][1] * 10, 240 + (locations[i][0] - 3) *10, 10, 10, Xwindow::A);
            }
        }
    }
}

