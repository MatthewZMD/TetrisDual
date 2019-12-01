#include "interface.h"

Interface::Interface(std::string fileName1, std::string fileName2, int l): file1 { fileName1 }, file2 { fileName2 }, startLevel { l }, g { std::make_shared<Game>(fileName1, fileName2, startLevel) } {}


/* Tries to match command cmd with the list cmdList and returns the matched command string.
   If cannot find the match string, or matched more than 1 command, return empty string
 */
std::string Interface::cmdInterpreter(const std::string& cmd, const std::vector<std::string>& cmdList, unsigned i){
    if(cmd.size() == 0 && cmdList.size() > 1){
        // Matched more than 1 command
        return "";
    }
    std::vector<std::string> newList;
    // Loop through the command
    for(unsigned l = 0; l < cmdList.size(); ++l){
        if(cmdList.at(l).size() > i && cmd.at(0) == cmdList.at(l).at(i)){
            newList.emplace_back(cmdList.at(l));
        }
    }
    if(newList.size() == 0){
        // Cannot find any match string
        return "";
    } else if (newList.size() == 1){
        return newList.at(0);
    } else {
        return cmdInterpreter(cmd.substr(1), newList, i + 1);
    }
}

/* The references of step and cmd, extract the number of multipliers from cmd and assign it to step. */
void Interface::cmdExtract(int& step, std::string& cmd){
    step = 1;
    int lastDiIndex = -1;
    for(unsigned i = 0; i < cmd.size(); i++){
        if(cmd.at(i) >= '0' && cmd.at(i) <= '9'){
            lastDiIndex = i;
        }
        else {
            break;
        }
    }
    if(lastDiIndex >= 0){
        step = std::stoi(cmd);
        cmd = cmd.substr(lastDiIndex + 1);
    }
}

void Interface::execFunc(std::istream& in, int step, std::string cmd) {
    if (cmd == "left") {
        g->left(in, step);
    }
    else if (cmd == "right") {
        g->right(in, step);
    }
    else if (cmd == "down") {
        g->down(step);
    }
    else if (cmd == "clockwise") {
        g->rotate(true, step);
    }
    else if (cmd == "counterclockwise") {
        g->rotate(false, step);
    }
    else if (cmd == "drop") {
        g->drop(in, step);
    }
    else if (cmd == "levelup") {
        g->levelup(step);
    }
    else if (cmd == "leveldown") {
        g->leveldown(step);
    }
    else if (cmd == "norandom") {
        std::string file;
        in >> file;
        g->norandom(file);
    }
    else if (cmd == "random") {
        g->random();
    }
    else if (cmd == "sequence") {
        std::string file;
        in >> file;

        std::ifstream fin;
        fin.open(file.c_str());

        while(cmdInterface(fin));

        fin.close();
    }
    else if (cmd == "restart") {
        std::cout << "Restarting..." << std::endl;
        g = std::make_shared<Game>(file1, file2, startLevel);
        std::cout << *(g->display) << std::endl;
    }
    else if (cmd == "I" || cmd == "J" || cmd == "L" || cmd == "O" || cmd == "S" || cmd == "Z" || cmd == "T") {
        g->replaceBlock(cmd);
    }
}

/* Main interface for analyzing and executing command cmd, also display the boards after */
bool Interface::cmdInterface(std::istream& in) {
    std::string cmd;
    if(in >> cmd){
        // Used for multiplier
        int step;

        // Extract numbers from cmd
        cmdExtract(step, cmd);

        // Interpret the command
        cmd = cmdInterpreter(cmd, cmdList);

        if (cmd == "") {
            std::cout << "This is not a valid command or it matches multiple commands!" << std::endl;
        }
        else {
            execFunc(in, step, cmd);
            std::cout << *(g->display) << std::endl;
        }

        return true;
    }
    return false;
}
