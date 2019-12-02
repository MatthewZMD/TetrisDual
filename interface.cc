#include "interface.h"

Interface::Interface(std::string fileName1, std::string fileName2, int l, bool isTextOnly): file1 { fileName1 }, file2 { fileName2 }, startLevel { l }, isTextOnly { isTextOnly }, g { std::make_shared<Game>(fileName1, fileName2, startLevel, isTextOnly) } {}

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
        if(g->left(step)){
            execAction(in);
        }
    }
    else if (cmd == "right") {
        if(g->right(step)){
            execAction(in);
        }
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
        if(g->drop(step)){
            execAction(in);
        }
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
        g = std::make_shared<Game>(file1, file2, startLevel, isTextOnly);
        std::cout << *(g->display) << std::endl;
    }
    else if (cmd == "I" || cmd == "J" || cmd == "L" || cmd == "O" || cmd == "S" || cmd == "Z" || cmd == "T") {
        g->replaceBlock(cmd);
    }
}

void Interface::execAction(std::istream & in) {
    std::string cmd;
    in >> cmd;
    cmdInterpreter(cmd, spList);
    if (cmd == "blind") {
        g->blind();
    }
    else if (cmd == "heavy") {
        g->heavy();
    }
    else if (cmd == "force") {
        std::string t;
        in >> t;

        CellType type = CellType::E;

        if (t == "I") {
            type = CellType::I;
        }
        else if (t == "J") {
            type = CellType::J;
        }
        else if (t == "L") {
            type = CellType::L;
        }
        else if (t == "O") {
            type = CellType::O;
        }
        else if (t == "S") {
            type = CellType::S;
        }
        else if (t == "Z") {
            type = CellType::Z;
        }
        else if (t == "T") {
            type = CellType::T;
        }
        g->force(type);
    }
}

bool Interface::cmdInterface(std::istream& in) {
    if (g->isAutoDrop()) {
        execFunc(in, 1, "drop");
        std::cout << *(g->display) << std::endl;
        return true;
    }

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
