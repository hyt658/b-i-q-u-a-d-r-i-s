#include "biquadris.h"
using std::cin;
using std::cout;
using std::endl;

Biquadris::Biquadris():
    b1{18, 11}, b2{18, 11}, highScore{0} {}

void Biquadris::setup() {
    int p1_lv, p2_lv;
    cout << "Enter the initial level for player 1: " << endl;
    try {cin >> p1_lv;}
    catch (...) {}
    cout << "Enter the initial level for player 2: " << endl;
}

