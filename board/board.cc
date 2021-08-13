#include "board.h"
#include "../blocks/block.h"
#include "../levels/level_zero.h"
#include "../levels/level_one.h"
#include "../levels/level_two.h"
#include "../levels/level_three.h"
#include "../levels/level_four.h"
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
Level* createLevel(int n, int seed, string path) {
    if (n == 0) {
        return new Level0{0, path};
    } else if (n == 1) {
        return new Level1{1};
    } else if (n == 2) {
        return new Level2{2};
    } else if (n == 3) {
        return new Level3{3, seed};
    } else {
        return new Level4{4, seed};
    }
}

void modifyAreaBlind(vector<vector<Cell>>& theboard, bool blind) {
    for (int row = 5; row < 14; ++row) {
        for (int col = 2; col < 8; ++col) {
            theboard[row][col].setBlind(blind);
        }
    }
}


//////////////////////////////////////////////////////////////////////
// field methods
//////////////////////////////////////////////////////////////////////

Board::Board(int row, int col):
    score{0}, 
    random_generate{true}, 
    curr_block{nullptr}, 
    next_block{nullptr}, 
    drop_times{1}, 
    lv0_path{""},
    generate_seed{0}
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

void Board::init(int n, int seed, string path) {
    generate_seed = seed;
    lv0_path = path;
    lv = createLevel(n, generate_seed, lv0_path);
    curr_block = lv->createRandBlock(this);
    next_block = lv->createRandBlock(this);

    auto locations = curr_block->getLocation();
    for (auto location : locations) {
        int row = location[0];
        int col = location[1];
        theBoard[row][col].setName(curr_block->getBlockType());
    }
}

int Board::getScore() {
    return score;
}

void Board::setLevel(int n) {
    delete lv;
    lv = createLevel(n, generate_seed, lv0_path);
    string curr_type = curr_block->getBlockType();
    delete curr_block;
    delete next_block;
    curr_block = lv->createCertainBlock(curr_type, this);
    next_block = lv->createRandBlock(this);
}

int Board::getLevel() {
    return lv->getlevel();
}

void Board::levelChange(bool up, int multiplier) {
    int curr_lv = lv->getlevel();
    if (up) {
        if (curr_lv == 4) {
            cout << "You have already reach the hardest level (lv4)." << endl;
        } else if (curr_lv + multiplier > 4) {
            setLevel(4);
        } else {
            setLevel(curr_lv + multiplier);
        }
    } else {
        if (curr_lv == 0) {
            cout << "You have already reach the easiest level (lv0)." << endl;
        } else if (curr_lv - multiplier < 0) {
            setLevel(0);
        } else {
            setLevel(curr_lv - multiplier);
        }
    }
}

void Board::update() {
    Blocks.emplace_back(curr_block);    // store the current block
    curr_block = next_block;            // update current block with next block

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
    bool placed = true;
    auto locations = curr_block->getLocation();
    for (auto location : locations) {
        int row = location[0];
        int col = location[1];
        if (theBoard[row][col].getName() != "empty") {
            theBoard[row][col].setName("-");
            placed = false;
        } else {
            theBoard[row][col].setName(curr_block->getBlockType());
        }
    }
    return placed;
}

int Board::checkCancel() {
    int cleaned_line = 0;
    int row = theBoard.size();
    int col = theBoard[0].size();

    for (int i = 0; i < row; ++i) {
        if (cellsPerRow[i] == col) {
            vector<Cell> temp;
            for (int j = 0; j < col; ++j) {
                Cell c {0, j};
                temp.emplace_back(c);

                theBoard[i][j].setName("empty");
                theBoard[i][j].notifyObservers();
            }

            for (int j = i; j >= 0; --j) {
                theBoard[j] = theBoard[j-1];
                for (int j = 0; j < col; ++j) {
                    theBoard[i][j].downRow(1);
                }
                cellsPerRow[j] = cellsPerRow[j-1];
            }
            theBoard[0] = temp;
            cleaned_line += 1;
        }
    }

    if (cleaned_line > 0) {
        score += square(cleaned_line + lv->getlevel());
        if (lv->getlevel() == 4) lv->resetBlockNum();
    } else if ((lv->getlevel() == 4) && (lv->getBlockNum() % 5 == 0)) {
        for (size_t i = theBoard.size()-1; i >= 0; --i) {
            if (theBoard[i][5].getName() == "empty") {
                theBoard[i][5].setName("*");
                break;
            }
        }
    }
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

bool Board::controlBlock(string command, int multiplier) {
    bool dropped = false;   // if the block cannot go further down
    bool success = false;   // if the command works successfully

    // create a temp board where change curr_block's cells back to empty 
    auto old_locations = curr_block->getLocation();
    vector<vector<Cell>> temp = theBoard;
    for (size_t i = 0; i < old_locations.size(); ++i) {
        int row_old = old_locations[i][0];
        int col_old = old_locations[i][1];
        temp[row_old][col_old].setName("empty");
    }

    // try to move block
    if (command == LEFT) {
        success = curr_block->moveLeft(temp, multiplier);
    } else if (command == RIGHT) {
        success = curr_block->moveRight(temp, multiplier);
    } else if (command == CLOCKWISE) {
        success = curr_block->rotate(true, temp, multiplier);
    } else if (command == COUNTER_CLOCKWISE) {
        success = curr_block->rotate(false, temp, multiplier);
    } else if (command == DOWN) { 
        success = curr_block->down(temp, multiplier);
    } else {
        success = curr_block->drop(temp);
        modifyAreaBlind(temp, false);
    }

    if (success) {
        // if block moved successed, overwrite theBoard with temp
        theBoard = temp;

        // plot the new locations of block on theBoard
        auto locations = curr_block->getLocation();
        for (size_t i = 0; i < locations.size(); ++i) {
            int row_new = locations[i][0];
            int col_new = locations[i][1];
            theBoard[row_new][col_new].setName(curr_block->getBlockType());

            // if dropped, attach the block as cells' observer
            // block will be notified when its any cell is cancelled
            if (curr_block->isDropped()) {
                theBoard[row_new][col_new].attach(curr_block);
                cellsPerRow[row_new] += 1;
                dropped = true;
            }
        }
    }
    return dropped;
}

void Board::setDebuff(string type, string block) {
    if (type == BLIND) {
        modifyAreaBlind(theBoard, true);
    } else if (type == HEAVY) {
        string curr_type = curr_block->getBlockType();
        string next_type = next_block->getBlockType();
        delete curr_block;
        delete next_block;
        lv->applyHeavy();
        curr_block = lv->createCertainBlock(curr_type, this);
        next_block = lv->createCertainBlock(next_type, this);
    } else {
        // change the cells of old blocks back to empty
        auto locations = curr_block->getLocation();
        for (auto location : locations) {
            int row = location[0];
            int col = location[1];
            theBoard[row][col].setName("empty");
        }
        delete curr_block;
        curr_block = lv->createCertainBlock(block, this);
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
        next = {"  L        ", "LLL        "};
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
    if (theBoard[row][col].isBlind()) {
        return "?";
    } else {
        return theBoard[row][col].getName();
    }
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
