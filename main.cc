#include "biquadris.h"

int main(int argc, char const *argv[]) {
    while (true) {
        Biquadris game;
        game.setup();
        if (game.play() == 0) {
            break;
        }
    }
    return 0;
}
