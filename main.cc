#include <memory>
#include <iostream>
#include <fstream>
#include "interface.h"

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
            srand(std::stoi(argv[++i]));
        }
        if(arg == "-scriptfile1"){
            fileName1 = argv[++i];
        }
        if(arg == "-scriptfile2"){
            fileName2 = argv[++i];
        }
        if(arg == "-startlevel"){
            startLevel = std::stoi(argv[++i]);
        }
    }

    std::shared_ptr<Interface> i = std::make_shared<Interface>(fileName1, fileName2, startLevel, textOnly);

    std::cout << *(i->g->display) << std::endl;

    while(true){
        try{
            // Read command
            i->cmdInterface(std::cin);
        } catch (const char* s){
            // Game Over
            std::cout << s << std::endl;
            break;
        }
    }
    // Game finished
    std::cout << "Player " << i->g->playerTurn + 1 << " has lost!" << std::endl;
    int thisHi = i->g->display->getScore(0) > i->g->display->getScore(1) ? i->g->display->getScore(0) : i->g->display->getScore(1);
    if(i->g->hiScore < thisHi){
        i->g->hiScore = thisHi;
        std::cout << "Congratulations! You have achieved the most useless high score you can ever get: " << thisHi << std::endl;
    }
}
