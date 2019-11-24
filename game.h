#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "board.h"

class Game {
    std::vector<Board*> boards;
    int hiScore;
    int playerTurn;
    Game();
};

#endif
