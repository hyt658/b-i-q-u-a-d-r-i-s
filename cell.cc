#include "cell.h"
#include <string>

Cell::Cell(int row, int col) : r{row}, c{col} {}

void Cell::setBlind(bool state) {
    blind = state;
}

bool Cell::isBlind() {
    return blind;
}

void Cell::setName(std::string name_) {
    name = name_;
}

std::string Cell::getName() {
    return name;
}

void Cell::notifyObservers() {
    for(auto i : observers) {
        i->notify(r, c);
    }
}
