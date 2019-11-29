#include <iostream>
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
    g->board1->setNext(g->board1->genNext());
    std::string cmd;
    int step = 1;//step need to be
    g->board2->drop();
    std::cout << *(g->display) << std::endl;
    g->board2->drop(); 
    std::cout << *(g->display) << std::endl;
    bool isRunning = true;
    while(isRunning){
        try{
            std::cin >> cmd;//TODO
            cmd = cmdInterpreter(cmd, cmdList);
	    
			    
            
        } catch (const std::string s){
            // Game Over
            std::cout << s << std::endl;
            isRunning = false;
        }
    }
    // Game finished
    std::cout << g->playerTurn << " has lost!" << std::endl;

}
