#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include <iostream>
#include <vector>
#include "game.h"

class Interface{
    const std::vector<std::string> cmdList = {"left", "right", "down", "clockwise", "counterclockwise",
        "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart",
        "I", "J", "L", "O", "S", "Z", "T"};
    std::string cmdInterpreter(const std::string& cmd, const std::vector<std::string>& cmdList, unsigned i = 0);
    void cmdExtract(int& step, std::string& cmd);
    void execFunc(std::istream& in, int step, std::string cmd);
    public:
    std::string file1, file2;
    int startLevel;
    bool isTextOnly;
    std::shared_ptr<Game> g;
    Interface(std::string fileName1, std::string fileName2, int l, bool isTextOnly);
    bool cmdInterface(std::istream& in);

};

#endif
