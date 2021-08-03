#ifndef _CELL_H_
#define _CELL_H_
#include <string>

class Cell {
    int r, c;
    bool blind = false;
    std::string name;

    public:
        Cell(int row, int col);
        void setBlind(bool state);
        bool isBlind();
        void setName(std::string name_);
        std::string getName();
};

#endif