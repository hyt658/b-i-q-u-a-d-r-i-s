#include "board.h"
#include "commands.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//////////////////////////////////////////////////////////////////////
// helper functions
//////////////////////////////////////////////////////////////////////

int square(int n) {
    return (n * n);
}

Level* judgeLevel(int n) {
    if (n == 0) {
        // return new level0();
    } else if (n == 1) {
        // return new level1();
    } else if (n == 2) {
        // return new level2();
    } else if (n == 3) {
        // return new level3();
    } else {
        // return new level4();
    }
}


//////////////////////////////////////////////////////////////////////
// field methods
//////////////////////////////////////////////////////////////////////

Board::Board(int row, int col):
    score{0}, curr_blcok{nullptr}, next_block{nullptr} 
{
    for (int i = 0; i < row; ++i) {
        vector<Cell> temp;
        for (int j = 0; j < col; ++j) {
            Cell c;
            temp.emplace_back(c);
        }
        theBoard.emplace_back(temp);
        cellsPerRow.emplace_back(0);
        temp.clear();
    }
}

void Board::init(int n) {
    lv = judgeLevel(n);
    curr_blcok = lv->createRandBlock(this);
    auto locations = curr_blcok->getLocation();
    for (auto location : locations) {
        int row = location[0];
        int col = location[1];
        theBoard[row][col].setName(curr_blcok->getBlockType());
    }
    next_block = lv->createRandBlock(this);
}

void Board::setLevel(int n) {
    delete lv;
    lv = judgeLevel(n);
    delete next_block;
    next_block = lv->createRandBlock(this);
}

int Board::getlevel() {
    return lv->getlevel();
}

void Board::levelUp() {
    /*
    int curr_lv = lv->getLvNum();
    if (curr_lv == 4) {
        cout << "You have already reach the hardest level." << endl;
    } else {
        delete lv;
        setlevel(curr_lv + 1);
    }
    */
}

void Board::levelDown() {
    /*
    int curr_lv = lv->getLvNum();
    if (curr_lv == 0) {
        cout << "You have already reach the easiest level." << endl;
    } else {
        delete lv;
        setLevel(curr_lv - 1);
    }
    */
}

int Board::update() {
    Blocks.emplace_back(curr_blcok);
    curr_blcok = next_block;
    auto locations = curr_blcok->getLocation();
    for (auto location : locations) {
        int row = location[0];
        int col = location[1];
        if (theBoard[row][col].getName() != "empty") {
            theBoard[row][col].setName("X");
            return 1;
        } else {
            theBoard[row][col].setName(curr_blcok->getBlockType());
        }
    }
    next_block = lv->createRandBlock(this);
    return 0;
}

void Board::assignNextBlock(string type) {
    delete next_block;
    next_block = lv->createCertainBlock(type, this);
}

void Board::controlBlock(string command) {      
    if (command == LEFT) {
        curr_blcok->moveLeft(theBoard);
    } else if (command == RIGHT) {
        curr_blcok->moveRight(theBoard);
    } else if (command == CLOCKWISE) {
        curr_blcok->rotate(true, theBoard);
    } else if (command == COUNTER_CLOCKWISE) {
        curr_blcok->rotate(false, theBoard);
    } else if (command == DOWN) { 
        curr_blcok->down(theBoard);
    } else {
        curr_blcok->drop(theBoard);
    }

    // plot the locations on cells
    auto locations = curr_blcok->getLocation();
    for (auto location : locations) {
        int row = location[0];
        int col = location[1];
        theBoard[row][col].setName(curr_blcok->getBlockType());
        if (command == "drop") theBoard[row][col].attach(curr_blcok);
    }
}

int Board::checkCancel() {
    int cleaned_line = 0;
    for (size_t i = 0; i < theBoard.size(); ++i) {
        if (cellsPerRow[i] == theBoard[i].size()) {
            for (size_t j = 0; j < theBoard[i].size(); ++j) {
                theBoard[i][j].setName("empty");
                cleaned_line += 1;
            }
        }
    }
    score += square(cleaned_line + lv->getlevel());
    return cleaned_line;
}

void Board::setDebuff(string type) {
    if (type == "blind") {
        for (int i = 2; i < 11; ++i) {
            for (int j = 2; j < 8; ++j) {
                
            }
        }
    }
}

void Board::printBoard() {
    
}

int Board::getScore() {
    return score;
}

void Board::notify(int n, int m) {
    score += square(n + 1);
}

Board::~Board() {
    for (auto block : Blocks) {
        delete block;
    }
}
