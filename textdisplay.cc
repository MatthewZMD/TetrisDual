#include "textdisplay.h"

TextDisplay::TextDisplay(int playerNum){
    std::vector<char> tempLine;
    std::vector<std::vector<char>> tempBoard;
    while (playerNum > 0) {
        for (int i = 0; i < 18; ++i) {
            for (int j = 0; j < 11; ++j) {
                tempLine.emplace_back(' ');
            }
            tempBoard.emplace_back(tempLine);
            tempLine.clear();
        }
        boardData.emplace_back(tempBoard);
        tempBoard.clear();
        --playerNum
    }
}


void TextDisplay::notify(Subject& s){
    
}
