#include "commands.h"

Commands::Commands() {
    dict["left"] = "left";
    dict["right"] = "right";
    dict["down"] = "down";
    dict["clockwise"] = "clockwise";
    dict["counterclockwise"] = "counterclockwise";
    dict["drop"] = "drop";
    dict["levelup"] = "levelup";
    dict["leveldown"] = "leveldown";
    dict["norandom"] = "norandom";
    dict["random"] = "random";
    dict["sequence"] = "sequence";
    dict["I"] = "I";
    dict["J"] = "J";
    dict["L"] = "L";
    dict["O"] = "O";
    dict["S"] = "S";
    dict["Z"] = "Z";
    dict["T"] = "T";
    dict["restart"] = "restart";
    dict["blind"] = "blind";
    dict["heavy"] = "heavy";
    dict["force"] = "force";
    dict["alias"] = "alias";
}

string Commands::translateCommand(string name) {
    return dict[name];
}

bool Commands::alias(string old_command, string new_command) {
    for (auto pair : dict) {
        if (pair.second == old_command) {
            dict.erase(pair.first);
            dict[new_command] = old_command;
            return true;
        }
    }
    return false;
}
