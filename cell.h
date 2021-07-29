#ifndef _CELL_H_
#define _CELL_H_
#include <string>

class Cell {
    int x, y;
    bool blind;
    std::string name;

    public:
        void setBlind(bool state);
        bool isBlind();
        void setName(std::string name);
        std::string getName();
};

#endif