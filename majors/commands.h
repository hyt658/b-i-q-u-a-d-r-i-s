#ifndef _COMMANDS_H_
#define _COMMANDS_H_
#include <map>
#include <string>
using std::string;
using std::map;

class Commands {
    map<string, string> dict;
    
    public:
        Commands();
        string translateCommand(string name);
        int alias(string old_command, string new_command);
};

#endif
