#include "block.h"

Block::Block(std::string new_type, bool isheavy) : type{new_type}, heavy{isheavy} {}

bool Block::isHeavy() {
    return heavy;
}

void Block::moveLeft(vector<vector<Cell>> board) {
    bool movable = true;
    for(i = 0; i < locations.size(); i++) {
        if(locations[i][1] >= 10 || board[locations[i][0]][locations[i][1]+1] != "empty") {
            movable = false;
        }
    }
    if(movable) {
        for(i = 0; i < locations.size(); i++) {
            locations[i][1]+=1;
        }
    }
}

void Block::down(vector<vector<Cell>> board) {
    bool movable = true;
    for(i = 0; i < locations.size(); i++) {
        if(locations[i][0] < 17 || board[locations[i][0]+1][locations[i][1]].isEmpty()==true) {
            movable = false;
        }
    }
    if(movable) {
        for(i = 0; i < locations.size(); i++) {
            locations[i][0]+=1;
        }
    }
}

void Block::moveLeft(vector<vector<Cell>> board) {
    bool movable = true;
    for(i = 0; i < locations.size(); i++) {
        if(locations[i][1] >= 1 || board[locations[i][0]][locations[i][1]-1].isEmpty()==true) {
            movable = false;
        }
    }
    if(movable) {
        for(size_t i = 0; i < locations.size(); i++) {
            locations[i][1]-=1;
        }
    }
}

void Block::drop(vector<vector<Cell>> board) {
    bool movable = true;
    while(movable) {
        for(size_t i = 0; i < locations.size(); i++) {
            if(locations[i][0] + 1 >= 17 && board[locations[i][0]+1][locations[i][1]].isEmpty()!=true) {
                movable = false;
            }
        }
        if(movable) {
            for(size_t i = 0; i < locations.size(); i++) {
                locations[i][0]+=1;
            }
        }
    }
}

std::string Block::getBlockType() {
    return type;
}

bool Block::isEmpty() {
    return theBlock.size() == 0;
}

void Block::notify(int n, int m) {
    int idx = 0;
    for(unsigned int i = 0; i < locations.size(); i++) {
        if(locations[i][0] == n, locations[i][1] == m) {
            locations.erase(locations.begin() + idx);
            break;
        }
        idx++;
    }
    if(locations.size() == 0) {
        notifyObservers();
    }
}

void Block::notifyObservers() {
    for(auto i : observers) {
        i->notify(generateLv);
    }
}
// This is a helper function that is used to determine whether the idx+1th points exists and is empty after adding a unit in its row and b units in its column.
bool Block::isFull(int idx, int a, int b, vector<vector<Cell>> board) {
    int row = locations[idx][0] + a;
    int col = locations[idx][1] + b;
    if(row < 0 || row > 17 || col < 0 || col > 10 || board[row][col] != empty) {
        return false;
    }
    return true;
}

void Block::tryRotate(int a, int b, int c, int d, int e, int f, int g, int h, vector<vector<Cell>> board) {
    if(isFull(0,a,b,board) && isFull(1,c,d,board) && isFull(2,e,f,board) && isFull(3,g,h,board) {
        locations[0][0]+=a;
        locations[0][1]+=b;
        locations[1][0]+=c;
        locations[1][1]+=d;
        locations[2][0]+=e;
        locations[2][1]+=f;
        locations[3][0]+=g;
        locations[3][1]+=h;
    }
}
