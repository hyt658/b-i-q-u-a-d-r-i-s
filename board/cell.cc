#include "cell.h"

Cell::Cell(int row, int col) : r{row}, c{col} {}

void Cell::setBlind(bool state) {
    blind = state;
}

bool Cell::isBlind() {
    return blind;
}

void Cell::downRow(int n) {
    r += n;
}

void Cell::setName(std::string name_) {
    name = name_;
}

std::string Cell::getName() {
    if (blind) {
        return "?";
    } else {
        return name;
    }
}

void Cell::notifyObservers() {
    for(auto i : observers) {
        i->notify(r, c);
    }
}
