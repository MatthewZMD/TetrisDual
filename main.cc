#include <iostream>
#include <sstream>
#include "game.h"

/* Tries to match command cmd with the list cmdList and returns the matched command string.
   If cannot find the match string, or matched more than 1 command, return empty string
 */
std::string cmdInterpreter(const std::string& cmd, const std::vector<std::string>& cmdList, unsigned i = 0){
    if(cmd.size() == 0 && cmdList.size() > 1){
        // Matched more than 1 command
        return "";
    }
    std::vector<std::string> newList;
    // Loop through the command
    for(long unsigned int l = 0; l < cmdList.size(); ++l){
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

/* The references of step and cmd, extract the number of multipliers from cmd  and assign it to step. */
void cmdExtract(int& step, std::string& cmd){
    step = 1;
    int lastDiIndex = -1;
    for(unsigned i = 0; i < cmd.size(); i++){
        if(cmd.at(i) >= '0' && cmd.at(i) <= '9'){
            lastDiIndex = i;
        }
    }
    if(lastDiIndex >= 0){
        step = std::stoi(cmd);
        cmd = cmd.substr(lastDiIndex + 1);
    }
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

    const std::vector<std::string> cmdList = {"left", "right", "down", "clockwise", "counterclockwise",
        "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart",
        "I", "J", "L", "O", "S", "Z", "T"};

    std::shared_ptr<Game> g = std::make_shared<Game>(fileName1, fileName2, startLevel);

    std::cout << *(g->display) << std::endl;

    // Command
    std::string cmd;

    // Used for multiplier
    int step;

    while(true){
        try{
            // Read command
            std::getline(std::cin, cmd);

            std::cout << cmd << std::endl;

            // Extract numbers from cmd
            cmdExtract(step, cmd);

            // Interpret the command
            cmd = cmdInterpreter(cmd, cmdList);

            if (cmd == "left") {
                g->left(step);
            }
            else if (cmd == "right") {
                g->right(step);
            }
            else if (cmd == "down") {
                g->down(step);
            }
            else if (cmd == "clockwise") {
                g->rotate(true);
            }
            else if (cmd == "counterclockwise") {
                g->rotate(false);
            }
            else if (cmd == "drop") {
                g->drop();
            }

            std::cout << *(g->display) << std::endl;
        } catch (const char* s){
            // Game Over
            std::cout << s << std::endl;
            break;
        }
    }

    // Game finished
    std::cout << "Player " << g->playerTurn << " has won!" << std::endl;

}
