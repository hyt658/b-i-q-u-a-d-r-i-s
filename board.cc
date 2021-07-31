#include "board.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int square(int n) {
    return (n * n);
}

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

void Board::setLevel(int n) {
    if (n == 0) {
        // lv = new level0(this);
    } else if (n == 1) {
        // lv = new level1(this);
    } else if (n == 2) {
        // lv = new level2(this);
    } else if (n == 3) {
        // lv = new level3(this);
    } else {
        // lv = new level4(this);
    }
    delete next_block;
    next_block = lv->createRandBlock();
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

void Board::generateBlock() {
    Blocks.emplace_back(curr_blcok);
    delete curr_blcok;
    curr_blcok = next_block;
    next_block = lv->createRandBlock();
}

void Board::assignNextBlock(string type) {
    delete next_block;
    next_block = lv->createCertainBlock(type);
}

void Board::controlBlock(string command) {      
    if (command == "left") {
        curr_blcok->moveLeft(theBoard);
    } else if (command == "right") {
        curr_blcok->moveRight(theBoard);
    } else if (command == "clockwise") {
        curr_blcok->rotate(true, theBoard);
    } else if (command == "counterclockwise") {
        curr_blcok->rotate(false, theBoard);
    } else { 
        
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

void Board::checkCancel() {
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
}

void Board::setDebuff(string type) {

}

void Board::printNextBlock() {
    
}

void Board::printCell(int row, int col) {

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
