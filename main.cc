#include <memory>
#include <iostream>
#include <fstream>
#include "game.h"

const std::vector<std::string> cmdList = {"left", "right", "down", "clockwise", "counterclockwise",
        "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart",
        "I", "J", "L", "O", "S", "Z", "T"};

// declarations
std::string cmdInterpreter(const std::string& cmd, const std::vector<std::string>& cmdList, unsigned i = 0);
void cmdExtract(int& step, std::string& cmd);
void execFunc(std::istream& in, int step, std::string cmd, std::shared_ptr<Game> g);
bool cmdInterface(std::istream& in, std::shared_ptr<Game> g);

/* Tries to match command cmd with the list cmdList and returns the matched command string.
   If cannot find the match string, or matched more than 1 command, return empty string
 */
std::string cmdInterpreter(const std::string& cmd, const std::vector<std::string>& cmdList, unsigned i){
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
void cmdExtract(int& step, std::string& cmd){
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

void execFunc(std::istream& in, int step, std::string cmd, std::shared_ptr<Game> g) {
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
        g->drop(in);
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
        g->norandom(in);
    }
    else if (cmd == "random") {
        g->random();
    }
    else if (cmd == "sequence") {
        std::string file;
        in >> file;

        std::ifstream fin;
        fin.open(file.c_str());

        while(cmdInterface(fin, g));

        fin.close();
    }
    else if (cmd == "restart") {
        //
    }
    else if (cmd == "I" || cmd == "J" || cmd == "L" || cmd == "O" || cmd == "S" || cmd == "Z" || cmd == "T") {
        g->replaceBlock(cmd);
    }
}

/* Main interface for analyzing and executing command cmd, also display the boards after */
bool cmdInterface(std::istream& in, std::shared_ptr<Game> g) {
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
            execFunc(in, step, cmd, g);
            std::cout << *(g->display) << std::endl;
        }

        return true;
    }
    return false;
}

/* Main Program */
int main(int argc, char* argv[]) {
    // True for text-only display, false showing both text and graphics
    bool textOnly = false;
    // Filenames for 2 players
    std::string fileName1 = "sequence1.txt", fileName2 = "sequence2.txt";
    // Starting level, default to 0
    int startLevel = 0;
    // Configure initial arguments
    for(int i = 0; i < argc; ++i){
        std::string arg = argv[i];
        if(arg == "-text"){
            textOnly = true;
        }
        if(arg == "-seed"){
            // Configure seed for RNG
            srand(std::atoi(argv[++i]));
        }
        if(arg == "-scriptfile1"){
            fileName1 = argv[++i];
        }
        if(arg == "-scriptfile2"){
            fileName2 = argv[++i];
        }
        if(arg == "-startlevel"){
            startLevel = std::atoi(argv[++i]);
        }
    }

    std::shared_ptr<Game> g = std::make_shared<Game>(fileName1, fileName2, startLevel);

    std::cout << *(g->display) << std::endl;

    while(true){
        try{
            // Read command
            cmdInterface(std::cin, g);
        } catch (const char* s){
            // Game Over
            std::cout << s << std::endl;
            break;
        }
    }

    // Game finished
    std::cout << "Player " << g->playerTurn + 1 << " has lost!" << std::endl;

    return 0;
}
