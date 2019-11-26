#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "board.h"
#include <memory>

class Game {
    std::vector<std::shared_ptr<Board>> boards;
    int hiScore;
    int playerTurn;
    Game();
    void heavy(std::shared_ptr<Board>> givenboard);
    void blind(std::shared_ptr<Board>> givenboard);
    void force(std::shared_ptr<Board>> givenboard, CellType giventype);
    void recover(std::shared_ptr<Board>> givenboard);
};

#endif
