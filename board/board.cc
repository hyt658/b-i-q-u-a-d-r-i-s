#include "board.h"
#include "../blocks/block.h"
#include "../levels/level_zero.h"
#include "../levels/level_one.h"
#include "../levels/level_two.h"
#include "../levels/level_three.h"
#include "../majors/commands.h"
using std::cin;
using std::cout;
using std::endl;


//////////////////////////////////////////////////////////////////////
// helper functions
//////////////////////////////////////////////////////////////////////

// square n
int square(int n) {
    return (n * n);
}

// return corresponding level by given n
Level* createLevel(int n, string path="") {
    if (n == 0) {
        return new Level0{0, path};
    } else if (n == 1) {
        return new Level1{1};
    } else if (n == 2) {
        return new Level2{2};
    } else if (n == 3) {
        return new Level3{3};
    } else {
        //return new Level4{4};
    }
}

void modifyAreaBlind(vector<vector<Cell>>& theboard, bool blind) {
    for (int row = 2; row < 11; ++row) {
        for (int col = 2; col < 8; ++col) {
            theboard[row][col].setBlind(blind);
        }
    }
}


//////////////////////////////////////////////////////////////////////
// field methods
//////////////////////////////////////////////////////////////////////

Board::Board(int row, int col):
    score{0}, random_generate{true}, curr_blcok{nullptr}, next_block{nullptr} 
{
    for (int i = 0; i < row; ++i) {
        vector<Cell> temp;
        for (int j = 0; j < col; ++j) {
            Cell c {i, j};
            temp.emplace_back(c);
        }
        theBoard.emplace_back(temp);
        cellsPerRow.emplace_back(0);
        temp.clear();
    }
}

void Board::init(int n, string path) {
    lv = createLevel(n, path);
    curr_blcok = lv->createRandBlock(this);
    auto locations = curr_blcok->getLocation();
    for (auto location : locations) {
        int row = location[0];
        int col = location[1];
        theBoard[row][col].setName(curr_blcok->getBlockType());
    }
    next_block = lv->createRandBlock(this);
}

int Board::getScore() {
    return score;
}

void Board::setLevel(int n) {
    delete lv;
    lv = createLevel(n);
    delete next_block;
    next_block = lv->createRandBlock(this);
}

int Board::getLevel() {
    return lv->getlevel();
}

void Board::levelUp() {
    int curr_lv = lv->getlevel();
    if (curr_lv == 4) {
        cout << "You have already reach the hardest level." << endl;
    } else {
        setLevel(curr_lv + 1);
    }
}

void Board::levelDown() {
    int curr_lv = lv->getlevel();
    if (curr_lv == 0) {
        cout << "You have already reach the easiest level." << endl;
    } else {
        setLevel(curr_lv - 1);
    }
}

void Board::update() {
    Blocks.emplace_back(curr_blcok);    // store the current block
    curr_blcok = next_block;            // update current block with next block

    // generate next block, random or from file
    if (random_generate) {
        next_block = lv->createRandBlock(this);
    } else {
        string next;
        infile >> next;
        next_block = lv->createCertainBlock(next, this);
    } 
}

bool Board::placeNextBlock() {
    auto locations = curr_blcok->getLocation();
    for (auto location : locations) {
        int row = location[0];
        int col = location[1];
        if (theBoard[row][col].getName() != "empty") {
            theBoard[row][col].setName("X");
            return false;
        } else {
            theBoard[row][col].setName(curr_blcok->getBlockType());
        }
    }
    return true;
}

int Board::checkCancel() {
    int cleaned_line = 0;
    for (size_t i = 0; i < theBoard.size(); ++i) {
        if (cellsPerRow[i] == theBoard[i].size()) {
            for (size_t j = 0; j < theBoard[i].size(); ++j) {
                theBoard[i][j].setName("empty");
                theBoard[i][j].notifyObservers();
                cleaned_line += 1;
            }
        }
    }
    score += square(cleaned_line + lv->getlevel());
    return cleaned_line;
}

void Board::randomGenerate() {
    if (infile.is_open()) infile.close();
    random_generate = true;
    delete next_block;
    next_block = lv->createRandBlock(this);
}

void Board::fileGenerate(string path) {
    infile.open(path);
    if (!infile.is_open()) throw "file opened failed.";
    random_generate = false;
    delete next_block;
    string next;
    infile >> next;
    next_block = lv->createCertainBlock(next, this);
}

void Board::assignNextBlock(string type) {
    delete next_block;
    next_block = lv->createCertainBlock(type, this);
}

void Board::controlBlock(string command) {
    auto old_location = curr_blcok->getLocation();
    bool success = false;
    if (command == LEFT) {
        success = curr_blcok->moveLeft(theBoard);
    } else if (command == RIGHT) {
        success = curr_blcok->moveRight(theBoard);
    } else if (command == CLOCKWISE) {
        success = curr_blcok->rotate(true, theBoard);
    } else if (command == COUNTER_CLOCKWISE) {
        success = curr_blcok->rotate(false, theBoard);
    } else if (command == DOWN) { 
        success = curr_blcok->down(theBoard);
    } else {
        success = curr_blcok->drop(theBoard);
        modifyAreaBlind(theBoard, false);
    }

    if (success) {
        // change old locations back to empty and plot the locations on cells
        auto locations = curr_blcok->getLocation();
        for (size_t i = 0; i < locations.size(); ++i) {
            int row_old = old_location[i][0];
            int col_old = old_location[i][1];
            int row_new = locations[i][0];
            int col_new = locations[i][1];
            theBoard[row_old][col_old].setName("empty");
            theBoard[row_new][col_new].setName(curr_blcok->getBlockType());
            if (curr_blcok->isDropped()) {
                theBoard[row_new][col_new].attach(curr_blcok);
                cellsPerRow[row_new] += 1;
            }
        }
    }
}

void Board::setDebuff(string type, string block) {
    if (type == BLIND) {
        modifyAreaBlind(theBoard, true);
    } else if (type == HEAVY) {
        lv->applyHeavy();
    } else {
        delete curr_blcok;
        curr_blcok = lv->createCertainBlock(block, this);
    }
}

vector<string> Board::getNextBlock() {
    vector<string> next;
    string block_type = next_block->getBlockType();
    if (block_type == I) {
        next = {"IIII       ", "           "};
    } else if (block_type == J) {
        next = {"J          ", "JJJ        "};
    } else if (block_type == O) {
        next = {"OO         ", "OO         "};
    } else if (block_type == L) {
        next = {"   L       ", "LLL        "};
    } else if (block_type == S) {
        next = {" SS        ", "SS         "};
    } else if (block_type == Z) {
        next = {"ZZ         ", " ZZ        "};
    } else {
        next = {"TTT        ", " T         "};
    }
    return next;
}

string Board::printCell(int row, int col) {
    return theBoard[row][col].getName();
}

void Board::notify(int n, int m) {
    score += square(n + 1);
}

Board::~Board() {
    if (infile.is_open()) infile.close();
    for (auto block : Blocks) {
        delete block;
    }
}
