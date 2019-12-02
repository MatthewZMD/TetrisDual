#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include <iostream>
#include <vector>
#include "game.h"

class Interface{
    const std::vector<std::string> cmdList = {"left", "right", "down", "clockwise", "counterclockwise",
        "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart",
        "I", "J", "L", "O", "S", "Z", "T"};
    const std::vector<std::string> spList = {"force", "heavy", "blind"};
    /* Tries to match command cmd with the list cmdList and returns the matched command string.
       If cannot find the match string, or matched more than 1 command, return empty string
    */
    std::string cmdInterpreter(const std::string& cmd, const std::vector<std::string>& cmdList, unsigned i = 0);
    /* The references of step and cmd, extract the number of multipliers from cmd and assign it to step. */
    void cmdExtract(int& step, std::string& cmd);
    // Read one normal function from istream in and execute it
    void execFunc(std::istream& in, int step, std::string cmd);
    // Read one special action from istream in and execute it
    void execAction(std::istream &in);
    public:
    std::string file1, file2;
    int startLevel;
    bool isTextOnly;
    std::shared_ptr<Game> g;
    Interface(std::string fileName1, std::string fileName2, int l, bool isTextOnly);
    /* Main interface for analyzing and executing command cmd, also display the boards after */
    bool cmdInterface(std::istream& in);
};

#endif
